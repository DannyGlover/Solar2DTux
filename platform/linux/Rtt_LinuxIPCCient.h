#pragma once

#ifndef LINUXIPCCLIENT_H
#define LINUXIPCCLIENT_H

#include "wx/ipc.h"
#include "Rtt_LinuxIPCConnectionBase.h"
#include "Rtt_LinuxIPCClientConnection.h"


// the default service name
//#define IPC_SERVICE "4242"
#define IPC_SERVICE "/tmp/solar2d_logconsole"

// the hostname
#define IPC_HOST "localhost"

// the IPC topic
#define IPC_TOPIC "IPC Solar2DTux"

// the name of the item we're being advised about
#define IPC_ADVISE_NAME "Item"
	
class Rtt_LinuxIPCClient: public wxClient
{
public:
    Rtt_LinuxIPCClient();
    ~Rtt_LinuxIPCClient();
    bool Connect(const wxString& sHost, const wxString& sService, const wxString& sTopic);
    void Disconnect();
    wxConnectionBase *OnMakeConnection() wxOVERRIDE;
    bool IsConnected() { return m_connection != NULL; }
	Rtt_LinuxIPCClientConnection *GetConnection() { return m_connection; }
protected:
    Rtt_LinuxIPCClientConnection  *m_connection;
};

#endif //LINUXIPCCLIENT_H