#pragma once


class Server
{
public:
    enum class Status
    {
        Uninitialised,
        Standby, // initialised, not running.
        Running,
        Exiting,
    };

    using Port = unsigned;

private:
    Status  m_Status    = Status::Uninitialised;
    Port    m_Port      = 11100;

public:

    /** Begin server logic loop and start accepting connnection from port. */
    void run(void);

    /** \return the currrent port the server is listening to. */
    Port port(void) const { return m_Port; }

    /** \return the status of the application. */
    Status status(void) const { return m_Status; }
};
