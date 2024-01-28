/*Question One (1) Remove Duplicates from Sorted Array*/
/*Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.*/
/*Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.*/

function removeDuplicates(nums) {
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === nums[i + 1]) {
      nums.splice(i, 1)
      i--
    }
  }
  return nums.length
}

/*Question Two (2) - Rotate Array*/
/*Given an array, rotate the array to the right by k steps, where k is non-negative.*/

function rotate(nums, k) {
  for (let i = 0; i < k; i++) {
    nums.unshift(nums.pop())
  }
  return nums
}

/*Question Three (3) - Contains Duplicate
/*Given an array of integers, find if the array contains any duplicates.
/*Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.*/

function containsDuplicate(nums) {
  let map = {}
  for (let i = 0; i < nums.length; i++) {
    if (map[nums[i]]) {
      return true
    } else {
      map[nums[i]] = 1
    }
  }
  return false
}

/*Question Four (4) - Single Number*/
/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.*/
function singleNumber(nums) {
  let map = {}
  for (let i = 0; i < nums.length; i++) {
    if (map[nums[i]]) {
      map[nums[i]]++
    } else {
      map[nums[i]] = 1
    }
  }
  for (let key in map) {
    if (map[key] === 1) {
      return key
    }
  }
}

// Tests
// Question One (1) Remove Duplicates from Sorted Array
let testOne = removeDuplicates([1, 1, 2])
let testTwo = removeDuplicates([0, 0, 1, 1, 1, 2, 2, 3, 3, 4])
console.log(testOne) // 2
console.log(testTwo) // 5

// Question Two (2) - Rotate Array
let testThree = rotate([1, 2, 3, 4, 5, 6, 7], 3)
let testFour = rotate([-1, -100, 3, 99], 2)
console.log(testThree) // [5,6,7,1,2,3,4]
console.log(testFour) // [3,99,-1,-100]

// Question Three (3) - Contains Duplicate
let testFive = containsDuplicate([1, 2, 3, 1])
let testSix = containsDuplicate([1, 2, 3, 4])
let testSeven = containsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2])
console.log(testFive) // true
console.log(testSix) // false
console.log(testSeven) // true

// Question Four (4) - Single Number
let testEight = singleNumber([2, 2, 1])
let testNine = singleNumber([4, 1, 2, 1, 2])

console.log(testEight) // 1
console.log(testNine) // 4
