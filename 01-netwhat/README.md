# netwhat

>"This project is an introduction to network problematics"

For further information, refer to the [project's PDF](../_PDFs/01-netwhat-en.pdf).

## Contents

* **[apuchill-ip_calc](./apuchill-ip_calc) folder:** program to calculate information about IP addresses and such.
* **[questions](./questions) folder:** questions answered on the netwhat test (printscreens).
* **file in the root:** file submitted to the project.

## Study Summary

### 1. IP (Internet Protocol)

* IPv4 address _size_: **32 bits**.
* IPv6 address _size_: **128 bits**.
* **Ping** uses ICMP protocol.

#### a) IP classes

* Ranges from **A to E**.
* **"A"** is the IP address class that has _the most host addresses available_ by default.
* **"C"** is the _default IP address class_ available.
* The _default subnet mask_ for a **class C** network is 255.255.255.0
* Summary:

| Class		| Starting Bits	| Start		| End				| Qty. Possible Addresses	| CIDR (network-machines)	| Default subnet mask	|
| :-:		| --:			| --:		| --:				| --:						| :--						| --:					|
| Class A	| 0				| 0.0.0.0	| 127.255.255.255	| 16.777.214				| /8 (1 byte - 3 bytes)		| 255.0.0.0				|
| Class B	| 10			| 128.0.0.0	| 191.255.255.255	| 65.535					| /16 (2 bytes - 2 bytes)	| 255.255.0.0			|
| Class C	| 110			| 192.0.0.0	| 223.255.255.255	| 256						| /24 (3 bytes - 1 byte)	| 255.255.255.0			|
| Class D	| 1110			| 224.0.0.0	| 239.255.255.255	| 							|							| Not defined			|
| Class E	| 1111			| 240.0.0.0	| 255.255.255.255	| 							|							| Not defined			|

#### b) Private IP addresses

* Class A: **10.0.0.0** to **10.255.255.255** (total of _16.777.216_ IP addresses);
* Class B: **172.16.0.0** to **172.31.255.255** (total of _1.048.576_ IP addresses);
* Class C: **192.168.0.0** to **192.168.255.255** (total of _65.536_ IP addresses).

### 4. DNS

* **"Domain name system"** translates internet domain names and host names into IP addresses.

### 5. TCP

* TCP does **_not_** support **broadcasting**.
* TCP is comparatively **slower** than UDP.
* TCP provides extensive **error checking mechanisms**. It is because it provides flow control and acknowledgement of data.
* TCP is **reliable** as it guarantees delivery of data to the destination router.
* **Sequencing of data** is a feature of TCP (this means that packets arrive in-order at the receiver).
* TCP is a **connection-oriented protocol**.

### 6. UDP (User Datagram Protocol)

* UDP supports **broadcasting**.
* UDP is **faster, simpler and more efficient** than TCP.
* UDP is a **datagram-oriented protocol**.
* UDP only has the **basic error control mechanism**.
* The delivery of data to the destination **_cannot_** be guaranteed in UDP.
* There is **_no_** **sequencing of data** in UDP. If ordering is required, it has to be managed by the application layer.

### 7. DHCP

* Supports both **IPv4 and IPv6**.
* Uses the **UDP protocol** at the Transport Layer.
* Mechanism that **automates IP configuration**, including IP address, subnet mask, default gateway and DNS information.

### 8. OSI model

* **Layers:** Application, Presentation, Session Transport, Network, Data Link, Physical.
