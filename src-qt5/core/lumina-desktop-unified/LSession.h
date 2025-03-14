//===========================================
//  Lumina-desktop source code
//  Copyright (c) 2012-2017, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef _LUMINA_DESKTOP_SESSION_H
#define _LUMINA_DESKTOP_SESSION_H

#include <global-includes.h>

class LSession : public LSingleApplication{
	Q_OBJECT
public:
	LSession(int &argc, char **argv);
	~LSession();

private:
	void CleanupSession();
	
	int VersionStringToNumber(QString version);
	QMediaPlayer *mediaObj;
	void playAudioFile(QString filepath);

	QTranslator *currTranslator;

public slots:
	void setupSession();  //called during startup only

	void StartLogout();
	void StartShutdown(bool skipupdates = false);
	void StartReboot(bool skipupdates = false);

	void reloadIconTheme(); //will emit the IconThemeChanged signal when ready
	void switchLocale(QString localeCode); //will emit the LocaleChanged signal when ready

private slots:
	void NewCommunication(QStringList);
	void launchStartupApps(); //used during initialization

	//Internal simplification functions
	void checkUserFiles();

signals:
	//General Signals
	void LocaleChanged();
	void IconThemeChanged();
	
};

#endif
