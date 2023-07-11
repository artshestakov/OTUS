#include <string>
#include <fstream>
#include "IPReader.h"
//-----------------------------------------------------------------------------
IPReader::IPReader(const std::string& file_path)
    : m_FilePath(file_path)
{

}
//-----------------------------------------------------------------------------
IPReader::~IPReader()
{

}
//-----------------------------------------------------------------------------
const std::string& IPReader::GetErrorString() const
{
    return m_ErrorString;
}
//-----------------------------------------------------------------------------
bool IPReader::Parse()
{
    if (m_FilePath.empty())
    {
        m_ErrorString = "Not specified file path";
        return false;
    }

    std::ifstream f(m_FilePath);
    if (f.fail())
    {
        m_ErrorString = "Error open file " + m_FilePath + " (" + std::to_string(errno) + ")";
        return false;
    }

    std::string tmp;
    tmp.reserve(32);

    size_t pos = 0;
    size_t line_num = 0;
    size_t index = 0;

    //Читаем файл построчно, где \n - конец строки
    while (std::getline(f, tmp, '\n'))
    {
        index = 0;
        ++line_num;

        //Формируем IP-адрес
        pos = tmp.find('\t');
        if (pos == std::string::npos)
        {
            m_ErrorString = "Invalid string by line " +std::to_string(line_num);
            return false;
        }

        tmp = tmp.substr(0, pos);
        IPAddress IP;

        while ((pos = tmp.find('.')) != std::string::npos)
        {
            try
            {
                IP.Address[index++] = StrToInt(tmp.substr(0, pos));

                tmp.erase(0, pos + 1);

                if (tmp.find('.') == std::string::npos && !tmp.empty())
                {
                    tmp += '.';
                }
            }
            catch (const std::exception& e)
            {
                m_ErrorString = "Can't convert octet to integer: " + std::string(e.what()) + " by line " + std::to_string(line_num);
                return false;
            }
        }

        AddressList.emplace_back(IP);
    }

    //файл не обязательно закрывать, он закроется автоматически при выходе из области видимости
    return true;
}
//-----------------------------------------------------------------------------
void IPReader::Sort()
{
    Sort(0);
    Sort(1);
    Sort(2);
    Sort(3);
}
//-----------------------------------------------------------------------------
void IPReader::PrintFull()
{
    for (const IPAddress& ip : AddressList)
    {
        std::cout << (int)ip.Address[0] << '.' << (int)ip.Address[1] << '.' << (int)ip.Address[2] << '.' << (int)ip.Address[3] << std::endl;
    }
}
//-----------------------------------------------------------------------------
void IPReader::Print1()
{
    for (const IPAddress& ip : AddressList)
    {
        if (ip.Address[0] == 1)
        {
            std::cout << (int)ip.Address[0] << '.' << (int)ip.Address[1] << '.' << (int)ip.Address[2] << '.' << (int)ip.Address[3] << std::endl;
        }
    }
}
//-----------------------------------------------------------------------------
void IPReader::Print4670()
{
    for (const IPAddress& ip : AddressList)
    {
        if (ip.Address[0] == 46 && ip.Address[1] == 70)
        {
            std::cout << (int)ip.Address[0] << '.' << (int)ip.Address[1] << '.' << (int)ip.Address[2] << '.' << (int)ip.Address[3] << std::endl;
        }
    }
}
//-----------------------------------------------------------------------------
void IPReader::PrintAny46()
{
    for (const IPAddress& ip : AddressList)
    {
        if (ip.Address[0] == 46 || ip.Address[1] == 46 || ip.Address[2] == 46 || ip.Address[3] == 46)
        {
            std::cout << (int)ip.Address[0] << '.' << (int)ip.Address[1] << '.' << (int)ip.Address[2] << '.' << (int)ip.Address[3] << std::endl;
        }
    }
}
//-----------------------------------------------------------------------------
void IPReader::Sort(int octet)
{
    bool is_need_more = false;

    for (size_t i = 0, c = AddressList.size() - 1; i < c; ++i)
    {
        IPAddress& ip_cur = AddressList[i];
        IPAddress& ip_next = AddressList[i + 1];

        if (octet == 0)
        {
            if (ip_cur.Address[octet] < ip_next.Address[octet])
            {
                std::swap(ip_cur, ip_next);
                is_need_more = true;
            }
        }
        else
        {
            if (ip_cur.Address[octet] < ip_next.Address[octet] &&
                ip_cur.Address[octet - 1] == ip_next.Address[octet - 1])
            {
                std::swap(ip_cur, ip_next);
                is_need_more = true;
            }
        }
    }

    if (is_need_more)
    {
        Sort(octet);
    }
}
//-----------------------------------------------------------------------------
unsigned char IPReader::StrToInt(const std::string& s)
{
    int i = std::stoi(s);

    if (i >= 0 && i <= 255)
    {
        return (unsigned char)i;
    }
    throw std::exception(("invalid range " + s + ". Must be from 0 to 255").c_str());
}
//-----------------------------------------------------------------------------
