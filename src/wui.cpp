//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wui.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wui.h"



_MainFrame::_MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxFrame(parent, id, title, pos, size, style)
{

    
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->SetMinSize(640,-1);
    this->SetSizer(topSizer);
    
    wxStaticBoxSizer* filePathSizer = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("选取文件")), wxHORIZONTAL);
    
    topSizer->Add(filePathSizer, 0, wxALL|wxEXPAND, 5);
    
    m_filePath = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_filePath->SetHint(wxT(""));
    #endif
    
    filePathSizer->Add(m_filePath, 1, wxALL, 5);
    
    m_Open = new wxButton(this, wxID_ANY, _("Open ..."), wxDefaultPosition, wxSize(-1,-1), 0);
    
    filePathSizer->Add(m_Open, 0, wxALL, 5);
    
    m_notebookInfo = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    m_notebookInfo->SetName(wxT("m_notebookInfo"));
    
    topSizer->Add(m_notebookInfo, 1, wxLEFT|wxRIGHT|wxEXPAND, 5);
    
    m_panelBrief = new wxPanel(m_notebookInfo, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebookInfo->AddPage(m_panelBrief, _("Brief"), false);
    
    wxFlexGridSizer* flexGridSizerBrief = new wxFlexGridSizer(11, 2, 0, 0);
    flexGridSizerBrief->SetFlexibleDirection( wxBOTH );
    flexGridSizerBrief->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizerBrief->AddGrowableCol(1);
    m_panelBrief->SetSizer(flexGridSizerBrief);
    
    m_staticTextCFBundleIdentifier = new wxStaticText(m_panelBrief, wxID_ANY, _("CFBundleIdentifier"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextCFBundleIdentifier, 0, wxALL, 5);
    
    m_CFBundleIdentifier = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_CFBundleIdentifier->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_CFBundleIdentifier, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextCFBundleDisplayName = new wxStaticText(m_panelBrief, wxID_ANY, _("CFBundleDisplayName"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextCFBundleDisplayName, 0, wxALL, 5);
    
    m_CFBundleDisplayName = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_CFBundleDisplayName->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_CFBundleDisplayName, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextCFBundleName = new wxStaticText(m_panelBrief, wxID_ANY, _("CFBundleName"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextCFBundleName, 0, wxALL, 5);
    
    m_CFBundleName = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_CFBundleName->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_CFBundleName, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextCFBundleExecutable = new wxStaticText(m_panelBrief, wxID_ANY, _("CFBundleExecutable"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextCFBundleExecutable, 0, wxALL, 5);
    
    m_CFBundleExecutable = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_CFBundleExecutable->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_CFBundleExecutable, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextMinimumOSVersion = new wxStaticText(m_panelBrief, wxID_ANY, _("MinimumOSVersion"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextMinimumOSVersion, 0, wxALL, 5);
    
    m_MinimumOSVersion = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_MinimumOSVersion->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_MinimumOSVersion, 0, wxALL|wxEXPAND, 5);
    
    m_staticText121 = new wxStaticText(m_panelBrief, wxID_ANY, _("CFBundleShortVersionString"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticText121, 0, wxALL, 5);
    
    m_CFBundleShortVersionString = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_CFBundleShortVersionString->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_CFBundleShortVersionString, 0, wxALL|wxEXPAND, 5);
    
    m_staticText125 = new wxStaticText(m_panelBrief, wxID_ANY, _("CFBundleVersion"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticText125, 0, wxALL, 5);
    
    m_CFBundleVersion = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_CFBundleVersion->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_CFBundleVersion, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextApplicationIdentifier = new wxStaticText(m_panelBrief, wxID_ANY, _("application-identifier"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextApplicationIdentifier, 0, wxALL, 5);
    
    m_applicationIdentifier = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_applicationIdentifier->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_applicationIdentifier, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextKeychainAccessGroups = new wxStaticText(m_panelBrief, wxID_ANY, _("keychain-access-groups"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextKeychainAccessGroups, 0, wxALL, 5);
    
    m_keychainAccessGroups = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_keychainAccessGroups->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_keychainAccessGroups, 0, wxALL|wxEXPAND, 5);
    
    m_staticTextSAGroups = new wxStaticText(m_panelBrief, wxID_ANY, _("com.apple.security.application-groups"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticTextSAGroups, 0, wxALL, 5);
    
    m_SAGroups = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_SAGroups->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_SAGroups, 0, wxALL|wxEXPAND, 5);
    
    m_staticText149 = new wxStaticText(m_panelBrief, wxID_ANY, _("IPA Type"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizerBrief->Add(m_staticText149, 0, wxALL, 5);
    
    m_IPAType = new wxTextCtrl(m_panelBrief, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY);
    #if wxVERSION_NUMBER >= 3000
    m_IPAType->SetHint(wxT(""));
    #endif
    
    flexGridSizerBrief->Add(m_IPAType, 0, wxALL|wxEXPAND, 5);
    
    m_panelInfoPlist = new wxPanel(m_notebookInfo, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebookInfo->AddPage(m_panelInfoPlist, _("Info.plist"), false);
    
    wxBoxSizer* boxSizerInfoPlist = new wxBoxSizer(wxVERTICAL);
    m_panelInfoPlist->SetSizer(boxSizerInfoPlist);
    
    m_infoPlist = new wxTextCtrl(m_panelInfoPlist, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_READONLY|wxTE_MULTILINE);
    
    boxSizerInfoPlist->Add(m_infoPlist, 1, wxALL|wxEXPAND, 0);
    
    m_statusBar = new wxStatusBar(this, wxID_ANY, wxSTB_DEFAULT_STYLE);
    m_statusBar->SetFieldsCount(1);
    this->SetStatusBar(m_statusBar);
    
    SetName(wxT("_MainFrame"));
    SetMinSize( wxSize(640,-1) );
    SetSizeHints(640,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    CentreOnParent(wxBOTH);
    // Connect events
    m_Open->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(_MainFrame::OnOpenButtonClicked), NULL, this);
    
}

_MainFrame::~_MainFrame()
{
    m_Open->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(_MainFrame::OnOpenButtonClicked), NULL, this);
    
}
