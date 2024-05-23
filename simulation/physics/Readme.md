# Симуляция уравнений движения

## Подготовка

1. Скачать [FlightGear](https://www.flightgear.org/download/)
2. Скачать [Python](https://www.python.org/downloads/), если он не скачан (лучше 3.8, но не обязательно)
3. Открыть терминал/консоль/cmd/powershell в папке с кодом и ввести:
    ```bash
   path_to_python -m venv .venv
   . .venv/bin/activate               # для linux
   .venv\Scripts\activate             # для windows
   pip install -r requirements.txt
   ```
4. Запустите visualize.py
5. Когда откроется окно FlightGear выставьте правильное время суток в Environment > Time Settings > Morning
6. Управляйте самолётом спомощью стрелочек вверх/вниз/вправо/влево
7. Чтобы закончить симуляцию, нажмите q, если не поможет (будет трясти самолёт) -- убейте процесс python спомощью менеджера процессов
8. Уравнения движения лежат в файлах engine.py и movement equations.py, там же вбиты все константы
