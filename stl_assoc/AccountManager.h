#pragma once

#include <string>
#include <map>
#include <exception>

class AccountException : public std::runtime_error
{
public:
    AccountException(std::string const& error):
        runtime_error(error)
    {
    }
};

class IAccount
{
public:
    virtual std::string GetName() const = 0;
    virtual bool IsAdmin() const = 0;
    
    virtual ~IAccount() = default;
};

class Account : public IAccount
{
private:
    std::string m_name;
    std::string m_password;
    
public:
    Account() = default;
    Account(std::string const& name);
    Account(std::string const& name, std::string const& password);
    
    std::string GetName() const override;
    bool IsAdmin() const override;
    
    std::string const& GetPassword() const;
    void SetPassword(std::string const& password);
};

class AccountManager
{
private:
    std::map<std::string, Account> m_accounts;
    bool m_isLoaded = false;
    
    bool Load();
    void Save();
    
    bool CheckIsValid(std::string const& str);
    
public:
    AccountManager();
    ~AccountManager();
    
    bool IsAccountExists(std::string const& name) const;
    void CreateAccount(std::string const& name, std::string const& password);
    IAccount const* Login(std::string const& name, std::string const& password);
};