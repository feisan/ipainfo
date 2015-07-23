//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wui.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef TMP_WUI_WUI_BASE_CLASSES_H
#define TMP_WUI_WUI_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/frame.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>

class _MainFrame : public wxFrame
{
protected:
    wxTextCtrl* m_filePath;
    wxButton* m_Open;
    wxNotebook* m_notebookInfo;
    wxPanel* m_panelBrief;
    wxStaticText* m_staticTextCFBundleIdentifier;
    wxTextCtrl* m_CFBundleIdentifier;
    wxStaticText* m_staticTextCFBundleDisplayName;
    wxTextCtrl* m_CFBundleDisplayName;
    wxStaticText* m_staticTextCFBundleName;
    wxTextCtrl* m_CFBundleName;
    wxStaticText* m_staticTextCFBundleExecutable;
    wxTextCtrl* m_CFBundleExecutable;
    wxStaticText* m_staticTextMinimumOSVersion;
    wxTextCtrl* m_MinimumOSVersion;
    wxStaticText* m_staticText121;
    wxTextCtrl* m_CFBundleShortVersionString;
    wxStaticText* m_staticText125;
    wxTextCtrl* m_CFBundleVersion;
    wxStaticText* m_staticTextApplicationIdentifier;
    wxTextCtrl* m_applicationIdentifier;
    wxStaticText* m_staticTextKeychainAccessGroups;
    wxTextCtrl* m_keychainAccessGroups;
    wxStaticText* m_staticTextSAGroups;
    wxTextCtrl* m_SAGroups;
    wxStaticText* m_staticText149;
    wxTextCtrl* m_IPAType;
    wxPanel* m_panelInfoPlist;
    wxTextCtrl* m_infoPlist;
    wxStatusBar* m_statusBar;

protected:
    virtual void OnOpenButtonClicked(wxCommandEvent& event) { event.Skip(); }

public:
    _MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("IPA File Infomation"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(640,-1), long style = wxDEFAULT_FRAME_STYLE);
    virtual ~_MainFrame();
};

#endif
