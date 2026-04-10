function printStudentDetails(student) {
  console.log("Student Details:");
  console.log(`Name: ${student.name}`);
  console.log(`ID: ${student.id}`);
  console.log(`Email: ${student.email}`);
  console.log(`Grade: ${student.grade}`);
  console.log(`GPA: ${student.gpa}`);
}

// Example usage:
const student = {
  name: "John Doe",
  id: "12345",
  email: "john@example.com",
  grade: "A",
  gpa: 3.8
};

printStudentDetails(student);
printStudentDetails({
  name: "Jane Smith",
  id: "67890",
  email: ""
})