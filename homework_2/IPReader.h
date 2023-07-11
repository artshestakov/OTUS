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

    //! �������� ��������� �������� ��������� ������
    const std::string& GetErrorString() const;

    //! ��������� �������
    bool Parse();

    //! ��������� ����������
    void Sort();

    //! ����� ����� ������ �������
    void PrintFull();

    //! ����� ������ ��� �������, ��� ������ ����� ����� 1
    void Print1();

    //! ����� ������ ��� �������, ��� ������ ����� ����� 46, � ������ 70
    void Print4670();

    //! ����� ������ ��� �������, ��� ����� ����� ����� ���� ����� 46
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
