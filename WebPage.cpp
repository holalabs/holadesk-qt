#include "WebPage.h"

WebPage::WebPage(QObject *parent)
{
    settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    settings()->setAttribute(QWebSettings::DnsPrefetchEnabled, true);
    settings()->setAttribute(QWebSettings::LocalStorageDatabaseEnabled, true);
    settings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
    settings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
    settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    settings()->enablePersistentStorage(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/holadesk");
    settings()->setOfflineStorageDefaultQuota(932838457459459);
    //settings()->setOfflineStoragePath(QFileInfo(settings->fileName()).absolutePath() + "/");
    settings()->setOfflineStoragePath(QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/holadesk");
    settings()->setOfflineWebApplicationCachePath(QDesktopServices::storageLocation(QDesktopServices::CacheLocation));
    settings()->setOfflineWebApplicationCacheQuota(932838457459459);

    settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
    settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);

    cookieJar = new CookieJar();
    networkAccessManager()->setCookieJar(cookieJar);

    native = new Native(this);
}

bool WebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type) {
    tempUrl = request.url();
    return QWebPage::acceptNavigationRequest (frame, request, type);
}
