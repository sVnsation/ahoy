//-----------------------------------------------------------------------------
// 2022 Ahoy, https://www.mikrocontroller.net/topic/525778
// Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//-----------------------------------------------------------------------------

#ifndef __WEB_H__
#define __WEB_H__

#include "dbg.h"
#include "ESPAsyncTCP.h"
#include "ESPAsyncWebServer.h"
#include "app.h"
#include "tmplProc.h"

class app;

class web {
    public:
        web(app *main, sysConfig_t *sysCfg, config_t *config, char version[]);
        ~web() {}

        void setup(void);
        void loop(void);

        void showIndex(AsyncWebServerRequest *request);
        void showCss(AsyncWebServerRequest *request);
        void showFavicon(AsyncWebServerRequest *request);
        void showNotFound(AsyncWebServerRequest *request);
        void showUptime(AsyncWebServerRequest *request);
        void showReboot(AsyncWebServerRequest *request);
        void showErase(AsyncWebServerRequest *request);
        void showFactoryRst(AsyncWebServerRequest *request);
        void showSetup(AsyncWebServerRequest *request);
        void showSave(AsyncWebServerRequest *request);

        void showStatistics(AsyncWebServerRequest *request);
        void showVisualization(AsyncWebServerRequest *request);
        void showLiveData(AsyncWebServerRequest *request);
        void showJson(AsyncWebServerRequest *request);
        void showWebApi(AsyncWebServerRequest *request);

        void showUpdateForm(AsyncWebServerRequest *request);
        void showUpdate(AsyncWebServerRequest *request);
        void showUpdate2(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final);

    private:
        String replaceHtmlGenericKeys(char *key);
        String showSetupCb(char* key);
        String showUpdateFormCb(char* key);

        AsyncWebServer *mWeb;

        config_t *mConfig;
        sysConfig_t *mSysCfg;
        char *mVersion;
        app *mMain;
};

#endif /*__WEB_H__*/