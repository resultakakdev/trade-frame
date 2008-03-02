// VuIndicies.cpp : implementation file
//

#include "stdafx.h"
#include "VuIndicies.h"

// CVuIndicies dialog

IMPLEMENT_DYNAMIC(CVuIndicies, CVuKeyValues)

CVuIndicies::CVuIndicies(CWnd* pParent /*=NULL*/)
	: CVuKeyValues(pParent) {

  static string sSymbols[] = {
    _T( "INDU.X" ),
    _T( "II1A.Z" ),
    _T( "II1D.Z" ),
    _T( "TRIN.Z" ),
    _T( "TICK.Z" ),
    _T( "VIX.XO" ),
    _T( "@YM#" ),
    _T( "@ES#" ),
    _T( "@NQ#" ),
    _T( "@ND#" ),
    _T( "OEX.XO" ),
    _T( "SPX.XO" ),
    _T( "PCRATIO.Z" ),
    _T( "COMPX.X" ),
    _T( "NDX.X" ),
    _T( "VXN.XO" ),
    _T( "RUT.XO" ),
    _T( "TIKI.Z" ),
    _T( "OIX.XO" ),
    _T( "TNX.XO" ),
    _T( "@NY#" ),
    _T( "VINA.Z" ),
    _T( "VIND.Z" ),
    _T( "IINA.Z" ),
    _T( "IIND.Z" ),
    _T( "" )
  };

  //BOOL b = CVuKeyValues::OnInitDialog();
  BOOL b = true;

  int i = 0;
  CRowKeyValues *row;
  while ( 0 != sSymbols[i].length() ) {
    row = AppendSymbol( sSymbols[i] );
    WatchSymbol( sSymbols[i], row );
    i++;
  }
}

CVuIndicies::~CVuIndicies() {
}

void CVuIndicies::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVuIndicies, CVuKeyValues)

END_MESSAGE_MAP()


// CVuIndicies message handlers
