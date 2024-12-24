# Client Management System

## Описание
Это простая консольная система учета клиентов, разработанная на С++, с использованием парадигмы ООП. Она позволяет:
- Добавлять/редактировать/удалять записи о клиентах.
- Сохранять и загружать данные в формате (**.csv**).
- Применять фильтры для поиска записи о клиенте.
- Применять фильтры для сортировки списка записей о клиентах.

## Требования
- Компилятор с поддержкой С++17.
- Установленный **make** для сборки проекта.

## Установка и запуск
1. Клонировать репозиторий с GitHub:
    ``` cmd
	git clone https://github.com/msbndn/client-management-system.git
	cd ClientManagementSystem
    ```
2. Собрать репозиторий:
    ``` cmd
	make
    ```
1. Запустить программу:
    ``` cmd
	build\ClientManagementSystem
    ```

## Структура данных
Программа использует файл "**data\clients.csv**" для хранения информации о клиентах. Формат данных:
``` csv
<ID,Name,Phone_number,email>
1,John Doe,+12345678901,doejohn@gmail.com
2,Alex Lion,+34567890123,lionalex@outlook.com
```

## Функционал
- Добавление записи о клиенте.
- Просмотр списка всех клиентов.
- Редактирование записи, указанного клиента.
- Удаление записи, указанного клиента.
- Сортировка списка по id/имени/номеру телефона/email.
- Поиск записи о клиенте по id/имени/номеру телефона/email.
- Загрузка данных из указанного файла **.csv**.
- Сохранение данных в указанный файл **.csv**.
- Автоматическое сохранение в файл по умолчанию "**data\clients.csv**".

## Пример использования
Пример использования можно найти в папке "**tests\\**", где находится файл с тестовыми данными "**test_data.csv**". 
Данный файл можно загрузить в программу вводом пути директории "**tests\test_data.csv**".
Далее вы можете попробовать добавить/изменить/удалить записи, использовать поиск и сортировку записей по заданному параметру, сохранить в указанную самостоятельно директорию.

## Авторы
- [Максим Баяндин](https://github.com/msbndn)

## Лицензия
- [MIT](https://github.com/msbndn/client-management-system/blob/main/LICENSE.md)
