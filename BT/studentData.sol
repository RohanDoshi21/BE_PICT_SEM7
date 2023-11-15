// SPDX-License-Identifier: MIT
pragma solidity 0.8;

contract StudentContract {
    struct Student {
        string name;
        uint128 age;
    }

    Student[] public studentArray;
    uint256 public totalEtherReceived;

    function addName(string memory name, uint128 age) public {
        studentArray.push(Student(name, age));
    }

    function getStudentLength() public view returns (uint256) {
        return studentArray.length;
    }

    function getStudent(uint128 index) public view returns (Student memory) {
        require(studentArray.length > index, "Out of Index");
        return studentArray[index];
    }
}
