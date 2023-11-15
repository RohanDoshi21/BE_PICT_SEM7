// SPDX-License-Identifier: MIT
pragma solidity ^0.8.22;

contract StudentData {
    struct Student {
        string name;
        int age;
    }

    Student[] public studentArray;

    function addStudent(string memory name, int age) public {
        for(uint i = 0; i<studentArray.length; i++) {
            if (studentArray[i].age == age)
            {
                revert("Roll No Exists");
            }
        }
        studentArray.push(Student(name, age));
    }

    function displayAllStudents() public view returns (Student[] memory) {
        return studentArray;
    }

        function getStudentLength() public view returns (uint256) {
        return studentArray.length;
    }

    function getStudent(uint128 index) public view returns (Student memory) {
        require(studentArray.length > index, "Out of Index");
        return studentArray[index];
    }
}

