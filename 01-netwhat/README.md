# Netwhat

>"This project is an introduction to network problematics"

For further information, refer to the [project's PDF](../_PDFs/).

## Study Summary

### 1. IP (Internet Protocol)

* IPv4 address _size_: **32 bits**.
* IPv6 address _size_: **128 bits**.
* **"Domain name system"** translates internet domain names and host names into IP addresses.
* **Ping** uses ICMP protocol.

### 2. IP classes

* Ranges from **A to E**.
* **"A"** is the IP address class that has _the most host addresses available_ by default.
* **"C"** is the _default IP address class_ available.
* The _default subnet mask_ for a **class C** network is 255.255.255.0

### 3. Private IP addresses

* **10.0.0.0** to **10.255.255.255** (total of _16.777.216_ IP addresses);
* **172.16.0.0** to **172.31.255.255** (total of _1.048.576_ IP addresses);
* **192.168.0.0** to **192.168.255.255** (total of _65.536_ IP addresses).

### 4. TCP

* TCP does **_not_** support **broadcasting**.
* TCP is comparatively **slower** than UDP.
* TCP provides extensive **error checking mechanisms**. It is because it provides flow control and acknowledgement of data.
* TCP is **reliable** as it guarantees delivery of data to the destination router.
* **Sequencing of data** is a feature of TCP (this means that packets arrive in-order at the receiver).
* TCP is a **connection-oriented protocol**.


### 5. UDP (User Datagram Protocol)

* UDP supports **broadcasting**.
* UDP is **faster, simpler and more efficient** than TCP.
* UDP is a **datagram-oriented protocol**.
* UDP only has the **basic error control mechanism**.
* The delivery of data to the destination **_cannot_** be guaranteed in UDP.
* There is **_no_** **sequencing of data** in UDP. If ordering is required, it has to be managed by the application layer.

### 6. DHCP

* Supports both **IPv4 and IPv6**.
* Uses the **UDP protocol** at the Transport Layer.
* Mechanism that **automates IP configuration**, including IP address, subnet mask, default gateway and DNS information.

### 7. OSI model

* **Layers:** Application, Presentation, Session Transport, Network, Data Link, Physical.
