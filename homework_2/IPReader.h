#pragma once
#ifndef _ISREADER_H_INCLUDED
#define _ISREADER_H_INCLUDED
//-----------------------------------------------------------------------------
#include <vector>
#include <iostream>
//-----------------------------------------------------------------------------
class IPReader
{
    struct IPAddress
    {
        IPAddress()
        {
            memset(Address, 0, 4);
        };

        unsigned char Address[4];
    };

public:
    explicit IPReader(const std::string &file_path);
    ~IPReader();

    //! Получить текстовое описание последней ошибки
    const std::string& GetErrorString() const;

    //! Выполняет парсинг
    bool Parse();

    //! Выполняет сортировку
    void Sort();

    //! Вывод всего списка адресов
    void PrintFull();

    //! Вывод только тех адресов, где первый октет равен 1
    void Print1();

    //! Вывод только тех адресов, где первый октет равен 46, а второй 70
    void Print4670();

    //! Вывод только тех адресов, где любой октет может быть равен 46
    void PrintAny46();

private:
    void Sort(int octet);
    inline unsigned char StrToInt(const std::string& s);

private:
    std::string m_ErrorString;
    std::string m_FilePath;
    std::vector<IPAddress> AddressList;
};
//-----------------------------------------------------------------------------
#endif
