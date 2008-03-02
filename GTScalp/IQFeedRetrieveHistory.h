#pragma once
//#include "BufferedSocket.h"
#include "IQFeedRetrieval.h"
//#include "Delegate.h"
#include "FastDelegate.h"
#include "TimeSeries.h"
#include "IQFeed.h"

// 
// ** IQFeedHistory
//

class IQFeedHistory: public CIQFeedRetrieval {
public:
  IQFeedHistory( void );
  virtual ~IQFeedHistory( void );
  typedef FastDelegate1<IQFeedHistory *> OnRequestCompleteHandler;
  void SetOnRequestComplete( OnRequestCompleteHandler function ) {
    OnRequestComplete = function;
  }
  virtual void FileRequest( const char *szSymbol, unsigned long nCount ) = 0;
  virtual void LiveRequest( const char *szSymbol, unsigned long nCount ) = 0;
protected:
  string m_sSymbol;
  bool m_bBusy;
  int m_cntRecords; 
  enum HistoryState {
    EDoingNothing, ECommandSent, EHandleResponse, EResponseSyntaxError, EResponseError, 
    EResponseExpectEndMsg, EResponseExpectEmptyLine, EResponseDone
  } m_stateHistory;
  void Parse( const char *str, string *results, unsigned short cnt );  // in:str, cnt, out:results
  OnRequestCompleteHandler OnRequestComplete;
  void FileRequest( const char *szPrefix, const char *szSymbol, unsigned long nCount );
  void LiveRequest( const char *szPrefix, const char *szSymbol, unsigned long nCount );
  virtual void OnPortMessage( const char *str ) = 0; // pure virtual needs override
  void OnNewResponse( const char *str );  // data from port
private:
};

//
// ** IQFeedHistoryHD
//

class IQFeedHistoryHD: public IQFeedHistory {
public:
  IQFeedHistoryHD( CBars *pBars );
  virtual ~IQFeedHistoryHD( void );
  virtual void FileRequest( const char *szSymbol, unsigned long nCount );
  virtual void LiveRequest( const char *szSymbol, unsigned long nCount );
protected:
  static const unsigned short nFields = 7;
  string fields[ nFields ];
  CBars *m_pBars;
  virtual void OnPortMessage( const char *str );
private:
};

//
// ** IQFeedHistoryHT
//

class IQFeedHistoryHT: public IQFeedHistory {
public:
  IQFeedHistoryHT( CQuotes *pQuotes, CTrades *pTrades );
  virtual ~IQFeedHistoryHT( void );
  virtual void FileRequest( const char *szSymbol, unsigned long nCount );
  virtual void LiveRequest( const char *szSymbol, unsigned long nCount );
protected:
  static const unsigned short nFields = 9;
  string fields[ nFields ];
  CQuotes *m_pQuotes;
  CTrades *m_pTrades;
  virtual void OnPortMessage( const char *str );
private:
};

