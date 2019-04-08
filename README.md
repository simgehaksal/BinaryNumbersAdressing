# BinaryNumbersAdressing
In this work I am going to establish some classes and operators which can be used for operations on binary numbers and addressing. I wrote a C++ program that utilizes operator overloading which appreciates the ability to program using notation closer to the target domain. Also, I established a class which can be used for arithmetic operations on binary numbers as well as IPv4, where computational representations of mathematical objects are manipulated with the same syntax as on paper.

Internet Protocol version 4 (IPv4) is still used for most of the Internet traffic today. It is one of the core protocols of standards-based internetworking methods in the Internet.

IPv4 uses 32-bit addresses which limits the address space to 4294967296 (232) addresses. Each IP address is made of four octets (eight bits each). For example IP address 158.94.1.1, can be represented as 10011110.01011110.00000001.00000001 in binary.

There is an "Address" class to represent IP addresses. The Address class will have private data members for the decimal and binary representations separately. The IPv4 addresses where the fist octet starts with 0 (in binary representation) are class A, with 10 are class B and 110 are class C.

For the second part of the project, I tried to establish another class "Network_Finder" which has three arrays of addresses. In first array, the IP addresses can be stored by the users and in the second one the Subnet Masks. In turn, these arrays should be traversed and logical “AND” operation should be applied to each address with the mask at the corresponding position. In turn, the third array should hold the result which is actually the network address of a given IPv4 address.

To sum up, I showed that we can use operators for any kind of topics. In that file, I represented them by using Network Protocols successfully. Have a nice work.
