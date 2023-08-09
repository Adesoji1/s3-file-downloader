function findMissingNumber(arr) {
  const n = 45; // Total number of integers in the original array
  let expectedSum = (n * (n + 1)) / 2; // Sum of first n natural numbers
  let actualSum = arr.reduce((sum, num) => sum + num, 0); // Sum of the elements in the array

  return expectedSum - actualSum;
}

// Test case
const numbersArray = [1, 2, 3, /* ... */, 44, 45]; // An array of the first 45 numbers with one missing number
const missingNumber = findMissingNumber(numbersArray);
console.log("Missing number:", missingNumber);
