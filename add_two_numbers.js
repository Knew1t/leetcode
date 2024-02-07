function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function createList(array) {
  const resultList = new ListNode(array[0], undefined);
  let tmp = resultList;
  for (let i = 1; i < array.length; i++) {
    const node = new ListNode(array[i], undefined);
    tmp.next = node;
    tmp = tmp.next;
  }
  printList(resultList);
  return resultList;
}

function printList(list) {
  let resultStr = "";
  resultStr += list?.val;
  tmp = list.next;
  while (tmp.next != null) {
    resultStr += tmp?.val;
    tmp = tmp.next;
  }
  resultStr += tmp?.val;
  console.log(resultStr);
}

const addTwoNumbers = function (l1, l2) {
  function add(l1, l2, carry = 0) {
    if (!l1 && !l2 && !carry) return null;
    const newVal = (l1?.val || 0) + (l2?.val || 0) + carry;
    const nextNode = add(l1?.next, l2?.next, (newVal > 10) ? 1 : 0);
    return new ListNode(newVal % 10, nextNode);
  }
  return add(l1, l2);
};

// const addTwoNumbers = function (l1, l2) {
//   let resultList = {};
//   let carry = 0;
//   let _l1 = l1;
//   let _l2 = l2;
//   let val1 = l1.val;
//   let val2 = l2.val;
//   while (true) {
//     const sum = val1 + val2 + carry;
//     let newNode;
//     if (sum < 10) {
//       newNode = new ListNode(sum, null);
//       carry = 0;
//     } else {
//       newNode = new ListNode(sum % 10, null);
//       carry = 1;
//     }
//     let tmp = resultList;
//     if (tmp.val != null) {
//       while (tmp.next != null) {
//         tmp = tmp.next;
//       }
//       tmp.next = newNode;
//     } else {
//       resultList = newNode;
//     }
//     _l1 = _l1 !== null ? _l1.next : null;
//     _l2 = _l2 !== null ? _l2.next : null;
//     val1 = _l1 != null ? _l1.val : 0;
//     val2 = _l2 != null ? _l2.val : 0;
//     if (_l1 == null && _l2 == null) {
//       if (carry != 0) {
//         tmp.next = new ListNode(1, undefined);
//       }
//       break;
//     }
//   }
//   return resultList;
// };

const a1 = [2, 4, 7];
const a2 = [5, 6, 4];
const l1 = createList(a1);
const l2 = createList(a2);
printList(addTwoNumbers(l1, l2));

let a = 0;

if (a) {
  console.log("hey");
}
a++;

if (a) {
  console.log("nothey");
}
