#pragma once
#ifndef _ISREADER_H_INCLUDED
#define _ISREADER_H_INCLUDED
//-----------------------------------------------------------------------------
#include <vector>
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

    const std::string& GetErrorString() const;
    bool Parse();

private:
    inline unsigned char StrToInt(const std::string& s);

private:
    std::string m_ErrorString;
    std::string m_FilePath;
    std::vector<IPAddress> AddressList;
};
//-----------------------------------------------------------------------------
#endif
