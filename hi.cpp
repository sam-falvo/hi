// BUILD WITH:  gcc -o hi hi.cpp `wx-config --cflags` `wx-config --libs` 

#include <iostream>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

/****** Command Identifiers ******/

enum {
	ID_HELLO = 1
};

/****** My Window ******/

class HiWindow : public wxFrame {
public:
	HiWindow(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	wxDECLARE_EVENT_TABLE();
	void OnHello(wxCommandEvent& e);
	void OnExit(wxCommandEvent& e);
};

wxBEGIN_EVENT_TABLE(HiWindow, wxFrame)
	EVT_MENU(ID_HELLO, HiWindow::OnHello)
	EVT_MENU(wxID_EXIT, HiWindow::OnExit)
wxEND_EVENT_TABLE()

HiWindow::HiWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame(NULL, wxID_ANY, title, pos, size) {
	wxMenu *mFile = new wxMenu;
	mFile->Append(ID_HELLO, "Hello &Mother...\tCtrl-M");
	mFile->AppendSeparator();
	mFile->Append(wxID_EXIT);

	wxMenuBar *mb = new wxMenuBar;
	mb->Append(mFile, "&File");
	SetMenuBar(mb);

	CreateStatusBar();
	SetStatusText("Smashing!");
}

void HiWindow::OnHello(wxCommandEvent& unusedEvent) {
	wxLogMessage("Hello father!");
}

void HiWindow::OnExit(wxCommandEvent& unusedEvent) {
	Close(true);
}

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

