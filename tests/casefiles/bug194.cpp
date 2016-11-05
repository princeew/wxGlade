// -*- C++ -*-
//
// generated by wxGlade e243dfc50cf6+ on Tue Aug 23 19:17:58 2016
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include "bug194.h"

// begin wxGlade: ::extracode
// end wxGlade



Frame194::Frame194(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, style)
{
    // begin wxGlade: Frame194::Frame194
    const wxString list_box_single_choices[] = {
        _("Listbox wxLB_SINGLE"),
    };
    list_box_single = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, list_box_single_choices, wxLB_SINGLE);
    const wxString list_box_multiple_choices[] = {
        _("Listbox wxLB_MULTIPLE"),
    };
    list_box_multiple = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, list_box_multiple_choices, wxLB_MULTIPLE);
    const wxString list_box_extended_choices[] = {
        _("Listbox wxLB_EXTENDED"),
    };
    list_box_extended = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, list_box_extended_choices, wxLB_EXTENDED);
    const wxString check_list_box_single_choices[] = {
        _("CheckListBox wxLB_SINGLE"),
    };
    check_list_box_single = new wxCheckListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, check_list_box_single_choices, wxLB_SINGLE);
    const wxString check_list_box_multiple_choices[] = {
        _("CheckListBox wxLB_MULTIPLE"),
    };
    check_list_box_multiple = new wxCheckListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, check_list_box_multiple_choices, wxLB_MULTIPLE);
    const wxString check_list_box_extended_choices[] = {
        _("CheckListBox wxLB_EXTENDED"),
    };
    check_list_box_extended = new wxCheckListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 1, check_list_box_extended_choices, wxLB_EXTENDED);

    set_properties();
    do_layout();
    // end wxGlade
}


void Frame194::set_properties()
{
    // begin wxGlade: Frame194::set_properties
    SetTitle(_("frame_1"));
    SetSize(wxSize(800, 600));
    list_box_single->SetSelection(0);
    list_box_multiple->SetSelection(0);
    list_box_extended->SetSelection(0);
    check_list_box_single->SetSelection(0);
    check_list_box_multiple->SetSelection(0);
    check_list_box_extended->SetSelection(0);
    // end wxGlade
}


void Frame194::do_layout()
{
    // begin wxGlade: Frame194::do_layout
    wxGridSizer* sizer_1 = new wxGridSizer(2, 3, 0, 0);
    sizer_1->Add(list_box_single, 1, wxALL|wxEXPAND, 5);
    sizer_1->Add(list_box_multiple, 1, wxALL|wxEXPAND, 5);
    sizer_1->Add(list_box_extended, 1, wxALL|wxEXPAND, 5);
    sizer_1->Add(check_list_box_single, 1, wxALL|wxEXPAND, 5);
    sizer_1->Add(check_list_box_multiple, 1, wxALL|wxEXPAND, 5);
    sizer_1->Add(check_list_box_extended, 1, wxALL|wxEXPAND, 5);
    SetSizer(sizer_1);
    Layout();
    // end wxGlade
}


class MyApp: public wxApp {
public:
    bool OnInit();
protected:
    wxLocale m_locale;  // locale we'll be using
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    m_locale.Init();
#ifdef APP_LOCALE_DIR
    m_locale.AddCatalogLookupPathPrefix(wxT(APP_LOCALE_DIR));
#endif
    m_locale.AddCatalog(wxT(APP_CATALOG));

    wxInitAllImageHandlers();
    Frame194* Bug194_Frame = new Frame194(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(Bug194_Frame);
    Bug194_Frame->Show();
    return true;
}