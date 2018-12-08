#!/usr/bin/env python2
from sys import argv
import pyipinfoio as info
import netaddr


def main():
    if len(argv) != 2:
        raise Exception("usage: takes an argumrnt for IP address to inspect")
    try:
        network = netaddr.IPNetwork(argv[1])
    except (netaddr.core.AddrFormatError, ValueError):
        raise ValueError("Network (%s) is not in CIDR presentation format" % argv[1])

    try:
        address = netaddr.IPAddress(argv[1])
    except (netaddr.core.AddrFormatError, ValueError):
        raise ValueError("Address (%s) is not in correct presentation format" % argv[1])
    ip = str(argv[1])
    inspect = info.IPLookup()
    country = inspect.lookup(ip)['country']
    city    = inspect.lookup(ip)['city']
    org     = inspect.lookup(ip)['org']
    print("Results for country of origin : %s" % country)
    print("Results for city              : %s" % city)
    print("Results for carrier/ISP       : %s" % org)


if __name__ == "__main__":
    main()


