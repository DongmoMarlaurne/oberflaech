///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TestingUI.h"

///////////////////////////////////////////////////////////////////////////

TestingUIBase::TestingUIBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	tabview = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxT("Wago IO Testing") );
	m_panel_settings = new wxPanel( tabview, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* layout_settings;
	layout_settings = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* settings_row_1;
	settings_row_1 = new wxGridSizer( 0, 2, 0, 0 );

	input_ip = new wxTextCtrl( m_panel_settings, wxID_ANY, _("192.168.1.2"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !input_ip->HasFlag( wxTE_MULTILINE ) )
	{
	input_ip->SetMaxLength( 15 );
	}
	#else
	input_ip->SetMaxLength( 15 );
	#endif
	input_ip->SetMinSize( wxSize( 200,-1 ) );

	settings_row_1->Add( input_ip, 0, wxALL, 5 );

	bt_connect = new wxButton( m_panel_settings, wxID_ANY, _("Verbinden"), wxDefaultPosition, wxDefaultSize, 0 );
	settings_row_1->Add( bt_connect, 0, wxALL, 5 );


	layout_settings->Add( settings_row_1, 1, wxEXPAND, 5 );


	m_panel_settings->SetSizer( layout_settings );
	m_panel_settings->Layout();
	layout_settings->Fit( m_panel_settings );
	tabview->AddPage( m_panel_settings, _("Settings"), false );
	m_panel_di = new wxPanel( tabview, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* layout_di;
	layout_di = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* di_row_1;
	di_row_1 = new wxGridSizer( 0, 2, 0, 0 );

	in_1 = new wxCheckBox( m_panel_di, wxID_ANY, _("I1"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_1->Add( in_1, 0, wxALL, 5 );

	in_5 = new wxCheckBox( m_panel_di, wxID_ANY, _("I5"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_1->Add( in_5, 0, wxALL, 5 );


	layout_di->Add( di_row_1, 1, wxEXPAND, 5 );

	wxGridSizer* di_row_2;
	di_row_2 = new wxGridSizer( 0, 2, 0, 0 );

	in_2 = new wxCheckBox( m_panel_di, wxID_ANY, _("I2"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_2->Add( in_2, 0, wxALL, 5 );

	in_6 = new wxCheckBox( m_panel_di, wxID_ANY, _("I6"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_2->Add( in_6, 0, wxALL, 5 );


	layout_di->Add( di_row_2, 1, wxEXPAND, 5 );

	wxGridSizer* di_row_3;
	di_row_3 = new wxGridSizer( 0, 2, 0, 0 );

	in_3 = new wxCheckBox( m_panel_di, wxID_ANY, _("I3"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_3->Add( in_3, 0, wxALL, 5 );

	in_7 = new wxCheckBox( m_panel_di, wxID_ANY, _("I7"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_3->Add( in_7, 0, wxALL, 5 );


	layout_di->Add( di_row_3, 1, wxEXPAND, 5 );

	wxGridSizer* di_row_4;
	di_row_4 = new wxGridSizer( 0, 2, 0, 0 );

	in_4 = new wxCheckBox( m_panel_di, wxID_ANY, _("I4"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_4->Add( in_4, 0, wxALL, 5 );

	in_8 = new wxCheckBox( m_panel_di, wxID_ANY, _("I8"), wxDefaultPosition, wxDefaultSize, 0 );
	di_row_4->Add( in_8, 0, wxALL, 5 );


	layout_di->Add( di_row_4, 1, wxEXPAND, 5 );


	m_panel_di->SetSizer( layout_di );
	m_panel_di->Layout();
	layout_di->Fit( m_panel_di );
	tabview->AddPage( m_panel_di, _("DI"), false );
	m_panel_do = new wxPanel( tabview, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* layout_do;
	layout_do = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* do_row_1;
	do_row_1 = new wxGridSizer( 0, 2, 0, 0 );

	out_1 = new wxCheckBox( m_panel_do, wxID_ANY, _("O1"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_1->Add( out_1, 0, wxALL, 5 );

	out_5 = new wxCheckBox( m_panel_do, wxID_ANY, _("O5"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_1->Add( out_5, 0, wxALL, 5 );


	layout_do->Add( do_row_1, 1, wxEXPAND, 5 );

	wxGridSizer* do_row_2;
	do_row_2 = new wxGridSizer( 0, 2, 0, 0 );

	out_2 = new wxCheckBox( m_panel_do, wxID_ANY, _("O2"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_2->Add( out_2, 0, wxALL, 5 );

	out_6 = new wxCheckBox( m_panel_do, wxID_ANY, _("O6"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_2->Add( out_6, 0, wxALL, 5 );


	layout_do->Add( do_row_2, 1, wxEXPAND, 5 );

	wxGridSizer* do_row_3;
	do_row_3 = new wxGridSizer( 0, 2, 0, 0 );

	out_3 = new wxCheckBox( m_panel_do, wxID_ANY, _("O3"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_3->Add( out_3, 0, wxALL, 5 );

	out_7 = new wxCheckBox( m_panel_do, wxID_ANY, _("O7"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_3->Add( out_7, 0, wxALL, 5 );


	layout_do->Add( do_row_3, 1, wxEXPAND, 5 );

	wxGridSizer* do_row_4;
	do_row_4 = new wxGridSizer( 0, 2, 0, 0 );

	out_4 = new wxCheckBox( m_panel_do, wxID_ANY, _("O4"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_4->Add( out_4, 0, wxALL, 5 );

	out_8 = new wxCheckBox( m_panel_do, wxID_ANY, _("O8"), wxDefaultPosition, wxDefaultSize, 0 );
	do_row_4->Add( out_8, 0, wxALL, 5 );


	layout_do->Add( do_row_4, 1, wxEXPAND, 5 );


	m_panel_do->SetSizer( layout_do );
	m_panel_do->Layout();
	layout_do->Fit( m_panel_do );
	tabview->AddPage( m_panel_do, _("DO"), true );

	bSizer1->Add( tabview, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	bt_connect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TestingUIBase::io_connect ), NULL, this );
	out_1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o1 ), NULL, this );
	out_5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o5 ), NULL, this );
	out_2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o2 ), NULL, this );
	out_6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o6 ), NULL, this );
	out_3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o3 ), NULL, this );
	out_7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o7 ), NULL, this );
	out_4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o4 ), NULL, this );
	out_8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( TestingUIBase::toggle_o8 ), NULL, this );
}

TestingUIBase::~TestingUIBase()
{
}
