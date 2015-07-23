#include "Ipa.h"

#include <wx/filedlg.h>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include <wx/tokenzr.h>
#include <wx/log.h> 

#include <plist/plist++.h>

Ipa::Ipa()
{
    m_info = new std::map<std::string, std::string>();
}

Ipa::~Ipa()
{ 
    delete m_info;
}

void Ipa::LoadFile(const wxString& filePath)
{
    m_info->clear();

    wxFFileInputStream in(filePath);
    wxZipInputStream zip(in);

    std::auto_ptr<wxZipEntry> entry;

    wxString appName;
    bool doInfoPList = false;
    bool doMobileProvision = false;

    while (entry.reset(zip.GetNextEntry()), entry.get() != NULL)
    {
        wxStringTokenizer tokenizer(entry->GetName(), "/");
        if (tokenizer.CountTokens()!=3 || tokenizer.GetNextToken()!="Payload" || !tokenizer.GetNextToken().EndsWith(".app", &appName)) {
            continue;
        }

        wxString fileName = tokenizer.GetNextToken();

        if (fileName == "Info.plist") {
            std::vector<char> buffer;
            buffer.resize(entry->GetSize());
            zip.Read(&buffer[0], entry->GetSize());
            this->processInfoPList(buffer);
            doInfoPList = true;
        } else if (fileName == "embedded.mobileprovision") {
            std::vector<char> buffer;
            buffer.resize(entry->GetSize());
            zip.Read(&buffer[0], entry->GetSize());
            this->processMobileProvision(buffer);
            doMobileProvision = true;
        }

        if (doInfoPList && doMobileProvision) {
            break;
        }
    }

    if (appName.IsEmpty()) {
        wxLogMessage("Cannot get ipa infomation.");
        return;
    }

}

std::string Ipa::operator[](const std::string& key) const
{
    return m_info->find(key)->second;
}


void Ipa::processInfoPList(const std::vector<char>& buffer)
{
    std::auto_ptr<PList::Dictionary> plist;

    if (buffer[0] != 'b') {
        plist.reset((PList::Dictionary *)PList::Structure::FromXml(std::string(buffer.begin(), buffer.end())));
    } else {
        plist.reset((PList::Dictionary *)PList::Structure::FromBin(buffer));
    }
            
    m_info->insert(std::make_pair("Info.plist", plist->ToXml()));

    // std::cout << m_info->find("Info.plist")->second << std::endl;

    PList::String *n_CFBundleIdentifier = static_cast<PList::String*> (plist->operator[]("CFBundleIdentifier"));
    if (n_CFBundleIdentifier)  {      
        m_info->insert(std::make_pair("CFBundleIdentifier", n_CFBundleIdentifier->GetValue()));
    } else {
        m_info->insert(std::make_pair("CFBundleIdentifier", "N/A"));
    }

    PList::String *n_CFBundleDisplayName = static_cast<PList::String*> (plist->operator[]("CFBundleDisplayName"));
    if (n_CFBundleDisplayName)  {      
        m_info->insert(std::make_pair("CFBundleDisplayName", n_CFBundleDisplayName->GetValue()));
    } else {
        m_info->insert(std::make_pair("CFBundleDisplayName", "N/A"));
    }

    PList::String *n_CFBundleName = static_cast<PList::String*> (plist->operator[]("CFBundleName"));
    if (n_CFBundleName)  {      
        m_info->insert(std::make_pair("CFBundleName", n_CFBundleName->GetValue()));
    } else {
        m_info->insert(std::make_pair("CFBundleName", "N/A"));
    }

    PList::String *n_CFBundleExecutable = static_cast<PList::String*> (plist->operator[]("CFBundleExecutable"));
    if (n_CFBundleExecutable)  {      
        m_info->insert(std::make_pair("CFBundleExecutable", n_CFBundleExecutable->GetValue()));
    } else {
        m_info->insert(std::make_pair("CFBundleExecutable", "N/A"));
    }

    PList::String *n_MinimumOSVersion = static_cast<PList::String*> (plist->operator[]("MinimumOSVersion"));
    if (n_MinimumOSVersion)  {      
        m_info->insert(std::make_pair("MinimumOSVersion", n_MinimumOSVersion->GetValue()));
    } else {
        m_info->insert(std::make_pair("MinimumOSVersion", "N/A"));
    }

    PList::String *n_CFBundleVersion = static_cast<PList::String*> (plist->operator[]("CFBundleVersion"));
    if (n_CFBundleVersion)  {      
        m_info->insert(std::make_pair("CFBundleVersion", n_CFBundleVersion->GetValue()));
    } else {
        m_info->insert(std::make_pair("CFBundleVersion", "N/A"));
    }

    PList::String *n_CFBundleShortVersionString = static_cast<PList::String*> (plist->operator[]("CFBundleShortVersionString"));
    if (n_CFBundleShortVersionString)  {      
        m_info->insert(std::make_pair("CFBundleShortVersionString", n_CFBundleShortVersionString->GetValue()));
    } else {
        m_info->insert(std::make_pair("CFBundleShortVersionString", "N/A"));
    }

}

void Ipa::processMobileProvision(const std::vector<char>& buffer)
{
    std::string profile = std::string(buffer.begin(), buffer.end());
    size_t bpos = profile.find("<?xml");
    if (bpos == std::string::npos) {
        return;
    }
    size_t epos = profile.rfind("</plist>");
    if (epos == std::string::npos) {
        return;
    }

    std::cout << profile.substr(bpos, epos + 8 - bpos) << std::endl;

    std::auto_ptr<PList::Dictionary> plist;
    plist.reset((PList::Dictionary *)PList::Structure::FromXml(profile.substr(bpos, epos + 8 - bpos)));

    PList::Dictionary *n_Entitlements = static_cast<PList::Dictionary*> (plist->operator[]("Entitlements"));

    PList::String *n_applicationIdentifier = static_cast<PList::String*> (n_Entitlements->operator[]("application-identifier"));
    if (n_applicationIdentifier)  {      
        m_info->insert(std::make_pair("application-identifier", n_applicationIdentifier->GetValue()));
    } else {
        m_info->insert(std::make_pair("application-identifier", "N/A"));
    }

    PList::Array *n_keychainAccessGroups = static_cast<PList::Array*> (n_Entitlements->operator[]("keychain-access-groups"));
    if (n_keychainAccessGroups)  {   
        uint32_t c = n_keychainAccessGroups->GetSize();
        int i;
        std::stringstream ss;
        for (i=0; i<c; i++) {
            if (i != 0) {
                ss << ", ";
            }
            PList::String *g = static_cast<PList::String*>(n_keychainAccessGroups->operator[](i));
            ss << g->GetValue();
        }
        m_info->insert(std::make_pair("keychain-access-groups", ss.str()));
    } else {
        m_info->insert(std::make_pair("keychain-access-groups", "N/A"));
    }

    PList::Array *n_SAGroups = static_cast<PList::Array*> (n_Entitlements->operator[]("com.apple.security.application-groups"));
    if (n_SAGroups)  {   
        uint32_t c = n_SAGroups->GetSize();
        int i;
        std::stringstream ss;
        for (i=0; i<c; i++) {
            if (i != 0) {
                ss << ", ";
            }
            PList::String *g = static_cast<PList::String*>(n_SAGroups->operator[](i));
            ss << g->GetValue();
        }
        m_info->insert(std::make_pair("com.apple.security.application-groups", ss.str()));
    } else {
        m_info->insert(std::make_pair("com.apple.security.application-groups", "N/A"));
    }

    PList::Boolean *n_getTaskAllow = static_cast<PList::Boolean*> (n_Entitlements->operator[]("get-task-allow"));
    bool getTaskAllow = false;
    if (n_getTaskAllow)  {
        getTaskAllow = n_getTaskAllow->GetValue();
        if (getTaskAllow) {
            m_info->insert(std::make_pair("get-task-allow", "true"));
        } else {
            m_info->insert(std::make_pair("get-task-allow", "false"));
        }
    } else {
        m_info->insert(std::make_pair("get-task-allow", "N/A"));
    }

    PList::Boolean *n_ProvisionsAllDevices = static_cast<PList::Boolean*> (plist->operator[]("ProvisionsAllDevices"));
    bool provisionsAllDevices = false;
    if (n_ProvisionsAllDevices)  {
        provisionsAllDevices = n_ProvisionsAllDevices->GetValue();
        if (provisionsAllDevices) {
            m_info->insert(std::make_pair("ProvisionsAllDevices", "true"));
        } else {
            m_info->insert(std::make_pair("ProvisionsAllDevices", "false"));
        }
    } else {
        m_info->insert(std::make_pair("ProvisionsAllDevices", "N/A"));
    }

    PList::Array *n_ProvisionedDevices = static_cast<PList::Array*> (plist->operator[]("ProvisionedDevices"));
    int provisionedDevicesCount = -1;
    if (n_ProvisionedDevices)  {
        provisionedDevicesCount = n_ProvisionedDevices->GetSize();
    }

    if (!getTaskAllow) {
        if (provisionsAllDevices) {
            m_info->insert(std::make_pair("IPAType", "In-House build"));
        } else if ( provisionedDevicesCount > 0){
            m_info->insert(std::make_pair("IPAType", "Ad-Hoc build"));
        } else {
            m_info->insert(std::make_pair("IPAType", "App Store build"));
        }
    } else {
        m_info->insert(std::make_pair("IPAType", "Development build"));
    }

}