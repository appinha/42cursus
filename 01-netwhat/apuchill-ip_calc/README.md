# IP Calculator

Program to calculate information about IP addresses and such, providing _just_ what is requested on the **netwhat test**.

### Printscreens

![Program printscreen - IP address information](./print1.png)

![Program printscreen - CIDR information](./print2.png)

![Program printscreen - subnet mask information](./print3.png)

## How to use

### Installation

Simply clone [this repository](https://github.com/appinha/ip_calc-netwhat-42cursus):

```
git clone https://github.com/appinha/ip_calc-netwhat-42cursus.git
```

### Running

`cd` to the program's cloned directory and run:

```
sh ipc.sh [IP address] [subnet mask or CIDR]
```

for information about the given **IP address**, or run:

```
sh ipc.sh [subnet mask or CIDR]
```

for information about the given **subnet mask/CIDR**.

### Tips

Set an **alias** for running the program, for instance:

```
alias ipc="cd ~/ip_calc-netwhat-42cursus && sh ipc.sh $1 $2"
```

Then, it suffices to run `ipc [IP address] [subnet mask or CIDR]` or `ipc [subnet mask or CIDR]`.
