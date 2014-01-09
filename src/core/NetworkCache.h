/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2013 - 2014 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_NETWORKCACHE_H
#define OTTER_NETWORKCACHE_H

#include <QtNetwork/QNetworkDiskCache>

namespace Otter
{

class NetworkCache : public QNetworkDiskCache
{
	Q_OBJECT

public:
	explicit NetworkCache(QObject *parent = NULL);

	void clearCache(int period = 0);
	void insert(QIODevice *device);
	QIODevice* prepare(const QNetworkCacheMetaData &metaData);
	QString getPathForUrl(const QUrl &url);
	QList<QUrl> getEntries() const;
	bool remove(const QUrl &url);

protected slots:
	void optionChanged(const QString &option, const QVariant &value);

private:
	QHash<QIODevice*, QUrl> m_devices;

signals:
	void cleared();
	void entryAdded(QUrl url);
	void entryRemoved(QUrl url);
};

}

#endif
