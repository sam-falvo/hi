#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

/****** My Window ******/

class HiWindow : public wxFrame {
public:
	HiWindow(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	void onExit(wxCommandEvent& e);
	wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(HiWindow, wxFrame)
wxEND_EVENT_TABLE()

/****** Application Entry Point ******/

class HiApp : public wxApp {
	public:
	virtual bool onInit();
};


bool HiApp::onInit() {
	return true;
}

wxIMPLEMENT_APP(HiApp);

