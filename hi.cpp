// BUILD WITH:  gcc -o hi hi.cpp `wx-config --cflags` `wx-config --libs` 

#include <iostream>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

/****** My Window ******/

class HiWindow : public wxFrame {
public:
	HiWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {}
};

/****** Application Entry Point ******/

class HiApp : public wxApp {
	HiWindow *m_window;

public:
	virtual bool OnInit();
};


bool HiApp::OnInit() {
	m_window = new HiWindow("Hi there!", wxDefaultPosition, wxDefaultSize);
	m_window->Show(true);
	return true;
}

wxIMPLEMENT_APP(HiApp);

