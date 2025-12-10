#ifndef SWSS_ORCHDAEMON_H
#define SWSS_ORCHDAEMON_H

#include "dbconnector.h"
#include "producerstatetable.h"
#include "consumertable.h"
#include "zmqserver.h"
#include "select.h"

#include "orchagent/portsorch.h"
#include "orchagent/fabricportsorch.h"
#include "orchagent/intfsorch.h"
#include "orchagent/neighorch.h"
#include "orchagent/routeorch.h"
#include "orchagent/flex_counter/flowcounterrouteorch.h"
#include "orchagent/nhgorch.h"
#include "orchagent/cbf/cbfnhgorch.h"
#include "orchagent/cbf/nhgmaporch.h"
#include "orchagent/copporch.h"
#include "orchagent/tunneldecaporch.h"
#include "orchagent/qosorch.h"
#include "orchagent/bufferorch.h"
#include "orchagent/mirrororch.h"
#include "orchagent/fdborch.h"
#include "orchagent/aclorch.h"
#include "orchagent/pbhorch.h"
#include "orchagent/pfcwdorch.h"
#include "orchagent/switchorch.h"
#include "orchagent/crmorch.h"
#include "orchagent/vrforch.h"
#include "orchagent/vxlanorch.h"
#include "orchagent/vnetorch.h"
#include "orchagent/countercheckorch.h"
#include "orchagent/flexcounterorch.h"
#include "orchagent/watermarkorch.h"
#include "orchagent/policerorch.h"
#include "orchagent/sfloworch.h"
#include "orchagent/debugcounterorch.h"
#include "orchagent/directory.h"
#include "orchagent/natorch.h"
#include "orchagent/isolationgrouporch.h"
#include "orchagent/mlagorch.h"
#include "orchagent/muxorch.h"
#include "orchagent/macsecorch.h"
#include "orchagent/p4orch/p4orch.h"
#include "orchagent/bfdorch.h"
#include "orchagent/srv6orch.h"
#include "orchagent/nvgreorch.h"
#include "orchagent/twamporch.h"
#include "orchagent/dash/dashaclorch.h"
#include "orchagent/dash/dashorch.h"
#include "orchagent/dash/dashrouteorch.h"
#include "orchagent/dash/dashvnetorch.h"
#include <sairedis.h>

using namespace swss;

class OrchDaemon
{
public:
    OrchDaemon(DBConnector *, DBConnector *, DBConnector *, DBConnector *, ZmqServer *);
    ~OrchDaemon();

    virtual bool init();
    void start();
    bool warmRestoreAndSyncUp();
    void getTaskToSync(vector<string> &ts);
    bool warmRestoreValidation();

    bool warmRestartCheck();

    void addOrchList(Orch* o);
    void setFabricEnabled(bool enabled)
    {
        m_fabricEnabled = enabled;
    }
    void setFabricPortStatEnabled(bool enabled)
    {
        m_fabricPortStatEnabled = enabled;
    }
    void setFabricQueueStatEnabled(bool enabled)
    {
        m_fabricQueueStatEnabled = enabled;
    }
    void logRotate();
private:
    DBConnector *m_applDb;
    DBConnector *m_configDb;
    DBConnector *m_stateDb;
    DBConnector *m_chassisAppDb;
    ZmqServer *m_zmqServer;

    bool m_fabricEnabled = false;
    bool m_fabricPortStatEnabled = true;
    bool m_fabricQueueStatEnabled = true;

    std::vector<Orch *> m_orchList;
    Select *m_select;
    
    std::chrono::time_point<std::chrono::high_resolution_clock> m_lastHeartBeat;

    void flush();

    void heartBeat(std::chrono::time_point<std::chrono::high_resolution_clock> tcurrent);

    void freezeAndHeartBeat(unsigned int duration);
};

class FabricOrchDaemon : public OrchDaemon
{
public:
    FabricOrchDaemon(DBConnector *, DBConnector *, DBConnector *, DBConnector *, ZmqServer *);
    bool init() override;
private:
    DBConnector *m_applDb;
    DBConnector *m_configDb;
};

#endif /* SWSS_ORCHDAEMON_H */
