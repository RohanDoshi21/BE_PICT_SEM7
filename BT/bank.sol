// SPDX-License-Identifier: MIT
pragma solidity 0.8;

contract Account {
    address public account;
    uint128 public balance;

    constructor() {
        account = msg.sender;
    }

    function deposit(uint128 amount) public  {
        balance += amount;
    }

    function withdraw(uint128 amount) public {
        require(balance > amount , "Insufficient Amount");
        balance -= amount;
    }

    function viewBalance() public view returns (uint128) {
        return balance;
    }
}

