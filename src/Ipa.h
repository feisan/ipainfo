#ifndef __Ipa_H__
#define __Ipa_H__

#include <wx/string.h>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>


class Ipa
{
public:
    Ipa();
    virtual ~Ipa();
    void LoadFile(const wxString& filePath);
    std::string operator[](const std::string& key) const;
private:
    std::map<std::string, std::string> *m_info;
    void processInfoPList(const std::vector<char>& buffer);
    void processMobileProvision(const std::vector<char>& buffer);
};

#endif  //__Ipa_H__