// SPDX-License-Identifier: MIT
pragma solidity 0.8;

contract StudentContract {
    struct Student {
        string name;
        uint128 age;
    }

    Student[] public studentArray;

    function addName(string memory _name, uint128 _age) public {
        Student memory newStud = Student({
            name : _name,
            age : _age
        });

        studentArray.push(newStud);
    }

    function getStudentLenght() public view returns (uint256) {
        return studentArray.length;
    }

    function getStudent(uint128 _index) public view returns (string memory, uint128) {
        require(studentArray.length > _index, "Out of Index");
        return (studentArray[_index].name, studentArray[_index].age);
    }
}