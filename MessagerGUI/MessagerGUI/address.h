#pragma once

#include<memory>
#include<string>
//#include<WinSock2.h>
#include <ctype.h>
#include <stdint.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <iphlpapi.h>
#include <io.h>
#include<iosfwd>
#include <time.h>
#include<iostream>

#pragma comment(lib,"Ws2_32.lib")

namespace rh
{
	class Address
	{
	public:
		typedef std::shared_ptr<Address> ptr;
		int getFamily()const;
		virtual	~Address() {}
		virtual const sockaddr* getAddr() = 0;
		virtual size_t getLen() = 0;
		virtual std::ostream insert(std::ostream& os) const;
		virtual std::string toStrng() const;
		bool operator <(Address& rhs) const;
		bool operator >(Address& rhs) const;
		bool operator !=(Address& rhs) const;

	};

	class IPAddress :public Address
	{
	public:
		typedef std::shared_ptr<IPAddress> ptr;
		virtual IPAddress::ptr boardcastAddress(uint32_t prefix_len) = 0;
		virtual IPAddress::ptr networkAddress(uint32_t prefix_len) = 0;
		virtual IPAddress::ptr subnetMask(uint32_t prefix_len) = 0;

		virtual uint32_t getPort() = 0;
		virtual void setPort(uint32_t port) = 0;

	};

	class IPv4Address :public IPAddress
	{
	public:
		typedef std::shared_ptr<IPv4Address> ptr;
		IPv4Address(uint32_t address = INADDR_ANY, uint32_t port = 0);
		IPv4Address(const sockaddr_in& address);

		virtual const sockaddr* getAddr() override;
		virtual size_t getLen() override;
		
		virtual IPAddress::ptr boardcastAddress(uint32_t prefix_len) override;
		virtual IPAddress::ptr networkAddress(uint32_t prefix_len) override;
		virtual IPAddress::ptr subnetMask(uint32_t prefix_len) override;

		virtual uint32_t getPort() override;
		virtual void setPort(uint32_t port) override;
		
	};

	class IPv6Address :public IPAddress
	{
	public:
		typedef std::shared_ptr<IPv4Address> ptr;
		IPv4Address(uint32_t address = INADDR_ANY, uint32_t port = 0);
		IPv4Address(const sockaddr_in& address);

		virtual const sockaddr* getAddr() override;
		virtual size_t getLen() override;

		virtual IPAddress::ptr boardcastAddress(uint32_t prefix_len) override;
		virtual IPAddress::ptr networkAddress(uint32_t prefix_len) override;
		virtual IPAddress::ptr subnetMask(uint32_t prefix_len) override;

		virtual uint32_t getPort() override;
		virtual void setPort(uint32_t port) override;

	};

	std::ostream& operator<<(std::ostream& os, const Address& addr);
}