#include "AccountManager.h"

#include <fstream>
#include <sstream>

const std::string Admin = "admin";
const std::string AdminPassword = "12345687";
const std::string AccountsPath = "accounts.txt";

Account::Account(std::string const& name) : m_name(name)
{
}

Account::Account(std::string const& name, std::string const& password) :
m_name(name), m_password(password)
{
}

std::string Account::GetName() const
{
    return m_name;
}

bool Account::IsAdmin() const
{
    return m_name == Admin;
}

std::string const& Account::GetPassword() const
{
    return m_password;
}

void Account::SetPassword(std::string const& password)
{
    m_password = password;
}


AccountManager::AccountManager()
{
    m_isLoaded = Load();
    if (m_isLoaded)
    {
        return;
    }
    m_accounts.clear();
    m_accounts[Admin] = Account(Admin, AdminPassword);
    Save();
    m_isLoaded = Load();
    if (m_isLoaded)
    {
        throw AccountException("Init failed");
    }
}

AccountManager::~AccountManager()
{
    if (m_isLoaded)
    {
        Save();
    }
}

bool AccountManager::Load()
{
    std::ifstream ifs(AccountsPath, std::ios::in);
    if (!ifs)
    {
        return false;
    }
    char line[1024];
    while (!ifs.eof())
    {
        std::string name;
        std::string password;
        ifs.getline(line, 1024);
        std::istringstream is(line);
        if (!is.eof())
        {
            is >> name;
            if (!is.eof())
            {
                is >> password;
            }
        }
        if (name.empty() || password.empty())
        {
            throw AccountException("Read failed");
        }
        m_accounts[name] = Account(name, password);
    }
    return true;
}

void AccountManager::Save()
{
    std::ofstream ofs(AccountsPath, std::ios::out|std::ios::trunc);
    if (!ofs)
    {
        throw AccountException("Save failed");
    }
    bool isFirst = true;
    for (auto& pair : m_accounts)
    {
        if (!isFirst)
        {
            ofs << std::endl;
        }
        else
        {
            isFirst = false;
        }
        Account const& acc = pair.second;
        ofs << acc.GetName() << " " << acc.GetPassword();
    }
}

bool AccountManager::IsAccountExists(std::string const& name) const
{
    return m_accounts.find(name) != m_accounts.end();
}

bool AccountManager::CheckIsValid(std::string const& str)
{
    return str.find(' ') == std::string::npos;
}

void AccountManager::CreateAccount(std::string const& name, std::string const& password)
{
    if (IsAccountExists(name))
    {
        throw AccountException("Account already exists");
    }
    if (!CheckIsValid(name))
    {
        throw AccountException("Invalid name");
    }
    if (!CheckIsValid(password))
    {
        throw AccountException("Invalid password");
    }
    m_accounts[name] = Account(name, password);
}

IAccount const* AccountManager::Login(std::string const& name, std::string const& password)
{
    auto it = m_accounts.find(name);
    if (it == m_accounts.end() || it->second.GetName() != password)
    {
        return nullptr;
    }
    return &it->second;
}