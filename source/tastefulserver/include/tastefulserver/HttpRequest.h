/**
 * (C) LGPL-3
 *
 * Tasteful Server <https://github.com/scheibel/tasteful-server>
 *
 * Copyright: 2012-2014 Lux, Scheibel
 * Authors:
 *     Roland Lux <rollux2000@googlemail.com>
 *     Willy Scheibel <willyscheibel@gmx.de>
 *
 * This file is part of Tasteful Server.
 *
 * Tasteful Server is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tasteful Server is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tasteful Server.  If not, see <http://www.gnu.org/licenses/>.
 **/

#pragma once

#include <QUrl>
#include <QHostAddress>

#include <tastefulserver/tastefulserver_api.h>

#include <tastefulserver/HttpMethod.h>
#include <tastefulserver/HttpMessage.h>
#include <tastefulserver/RequestParameters.h>

namespace tastefulserver {

class TASTEFULSERVER_API HttpRequest : public HttpMessage
{
public:
    HttpRequest();
    HttpRequest(const HttpMethod & method, const QString & requestUri, const HttpVersion & httpVersion);

    bool isBad() const;
    void markBad();

    void setHttps(bool isHttps);

    bool isXMLHttpRequest() const;

    const QHostAddress & address() const;
    void setAddress(const QHostAddress & address);

    unsigned port() const;
    void setPort(unsigned port);

    HttpMethod getMethod() const;
    QUrl getUrl() const;
    QString getPath() const;
    QString getRequestUri() const;

    RequestParameters & getParameters();
    const RequestParameters & getParameters() const;

    virtual QByteArray toByteArray() const;

    void finalize();

protected:
    QHostAddress m_address;
    bool m_bad;
    unsigned m_port;
    HttpMethod m_method;
    QString m_requestUri;
    QUrl m_url;
    RequestParameters m_requestParams;

    void interpretHeaders();
    void interpretContent();
};

} // namespace tastefulserver
