#include "WeatherStation.h"
#include "StatisticsWidget.h"
#include "GeneralWidget.h"

int main()
{
    WeatherStation ws;
    GeneralWidget gw;
    StatisticsWidget sw;
    
    // подписываем виджеты на события метеостанции
    ws.AddObserver(&gw);
    ws.AddObserver(&sw);
    
    ws.Set(15.0, 60.0);
    ws.Set(16.3, 61.2);
    ws.Set(17.8, 64.5);
    
    // отписываем от событий виджет статистики. он перестанет печатать обновления
    ws.RemoveObserver(&sw);
    ws.Set(19.0, 66.0);
    ws.Set(18.8, 65.5);
}