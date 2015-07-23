#include "MainFrame.h"

#include <wx/filedlg.h>
#include <wx/zipstrm.h>
#include <wx/wfstream.h>
#include <wx/tokenzr.h>
#include <wx/log.h> 

#include <plist/plist++.h>

#include "Ipa.h"

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size)
    : _MainFrame(parent, id, title, pos, size)
{
}

MainFrame::~MainFrame()
{ 
}

void MainFrame::OnOpenButtonClicked(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog openFileDialog(this, _("Open IPA file"), "", "",
                       "IPA files (*.ipa)|*.ipa", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return; 

    this->ProcessIPA(openFileDialog.GetPath());
}

void MainFrame::ProcessIPA(const wxString& ipaFilePath)
{
    m_filePath->SetValue(ipaFilePath);
    
    Ipa ipa;
    ipa.LoadFile(ipaFilePath);

    m_CFBundleIdentifier->SetValue(ipa["CFBundleIdentifier"]);
    m_CFBundleDisplayName->SetValue(ipa["CFBundleDisplayName"]);
    m_CFBundleName->SetValue(ipa["CFBundleName"]);
    m_CFBundleExecutable->SetValue(ipa["CFBundleExecutable"]);
    m_MinimumOSVersion->SetValue(ipa["MinimumOSVersion"]);
    m_CFBundleVersion->SetValue(ipa["CFBundleVersion"]);
    m_CFBundleShortVersionString->SetValue(ipa["CFBundleShortVersionString"]);

    m_applicationIdentifier->SetValue(ipa["application-identifier"]);
    m_keychainAccessGroups->SetValue(ipa["keychain-access-groups"]);
    m_SAGroups->SetValue(ipa["com.apple.security.application-groups"]);
    m_IPAType->SetValue(ipa["IPAType"]);

    m_infoPlist->SetValue(ipa["Info.plist"]);
    
}

