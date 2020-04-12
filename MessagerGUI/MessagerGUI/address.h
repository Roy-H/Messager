#pragma once

#include<memory>
#include<string>
//#include<WinSock2.h>
#include <ctype.h>
#include <stdint.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <io.h>
#include<iosfwd>
#include <time.h>
#include<iostream>
#include <stdint.h>

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
		
		virtual std::string toStrng() const;
		bool operator <(Address& rhs) const;
		bool operator >(Address& rhs) const;
		bool operator !=(Address& rhs) const;
	
		virtual const sockaddr* getAddr() const = 0;

		virtual socklen_t getAddrLen() const = 0;
		virtual std::ostream& insert(std::ostream& os) const = 0;
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
		IPv6Address(unsigned long address = INADDR_ANY, unsigned long port = 0);
		IPv6Address(const sockaddr_in& address);

		virtual const sockaddr* getAddr() override;
		virtual size_t getLen() override;

		virtual IPAddress::ptr boardcastAddress(uint32_t prefix_len) override;
		virtual IPAddress::ptr networkAddress(uint32_t prefix_len) override;
		virtual IPAddress::ptr subnetMask(uint32_t prefix_len) override;

		virtual uint32_t getPort() override;
		virtual void setPort(uint32_t port) override;

	};

	class UnknownAddress : public Address {
	public:
		typedef std::shared_ptr<UnknownAddress> ptr;
		UnknownAddress(int family);
		UnknownAddress(const sockaddr& addr);
		const sockaddr* getAddr() const override;
		sockaddr* getAddr() override;
		socklen_t getAddrLen() const override;
		std::ostream& insert(std::ostream& os) const override;
	private:
		sockaddr m_addr;
	};


	std::ostream& operator<<(std::ostream& os, const Address& addr);
}