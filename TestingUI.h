///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class TestingUIBase
///////////////////////////////////////////////////////////////////////////////
class TestingUIBase : public wxFrame
{
	private:

	protected:
		wxNotebook* tabview;
		wxPanel* m_panel_settings;
		wxTextCtrl* input_ip;
		wxButton* bt_connect;
		wxPanel* m_panel_di;
		wxCheckBox* in_1;
		wxCheckBox* in_5;
		wxCheckBox* in_2;
		wxCheckBox* in_6;
		wxCheckBox* in_3;
		wxCheckBox* in_7;
		wxCheckBox* in_4;
		wxCheckBox* in_8;
		wxPanel* m_panel_do;
		wxCheckBox* out_1;
		wxCheckBox* out_5;
		wxCheckBox* out_2;
		wxCheckBox* out_6;
		wxCheckBox* out_3;
		wxCheckBox* out_7;
		wxCheckBox* out_4;
		wxCheckBox* out_8;

		// Virtual event handlers, override them in your derived class
		virtual void io_connect( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o1( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o5( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o2( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o6( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o3( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o7( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o4( wxCommandEvent& event ) { event.Skip(); }
		virtual void toggle_o8( wxCommandEvent& event ) { event.Skip(); }


	public:

		TestingUIBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Testing UI"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~TestingUIBase();

};

