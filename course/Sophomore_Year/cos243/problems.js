module.exports = [
  {
	re: /a+(b+)?/,
	targets: [
	  { string: '', expected: false },
	  { string: 'a', expected: true },
	  { string: 'babba', expected: true }
	]
  },
  {
	re: /^$/,
	targets: [
	  { string: 'a', expected: false },
	  { string: '', expected: true },
	  { string: 'babba', expected: false }
	]
  },
  { re: /^...$/,
	targets: [
	  { string: '', expected: false },
	  { string: 'ab', expected: false },
	  { string: 'abcd', expected: false },
	  { string: 'abc', expected: true },
	  { string: 'bcd', expected: true },
	  { string: '$#@', expected: true },
	]
  },
  {
	re: /^[a-z][a-z][a-z]$/,
	targets: [
	  { string: '', expected: false },
	  { string: 'abc', expected: true },
	  { string: 'babc', expected: false }
	]
  },
  {
	re: /\w+[^z]\b/,
	targets: [
	  { string: 'abcxyzzy', expected: true },
	  { string: 'abcxyzz', expected: false },
	  { string: 'xyzy', expected: true },
	  { string: 'xyzzzzzzy', expected: true },
	]
  },
  {
	re: /(\d{3}-\d{4})|(\d-\d{3}-\d{3}-\d{4})|(\d-\d{3}-\d{3}-\d{4}\sext\.\s\d{1,4})/,
	targets: [
	  { string: '555-1212', expected: true },
	  { string: '1-800-555-1234', expected: true },
	  { string: '1-800-555-4321 ext. 42', expected: true },
	  { string: 'babc', expected: false }
	]
  },
  {
	re: /(^\d{3}-\d{4}$)|(^\d-\d{3}-\d{3}-\d{4}$)/,
	targets: [
	  { string: '555-1212', expected: true },
	  { string: '1-800-555-1212', expected: true },
	  { string: '1-800-555-1212 ext. 42', expected: false },
	  { string: 'babc', expected: false }
	]
  },
  {
	re: /\d{1,2}-[A-Z][a-z][a-z]-\d{4}/,
	targets: [
	  { string: '4-Jul-1776', expected: true },
	  { string: '25-Dec-1961', expected: true },
	  { string: '25-dec-1961', expected: false },
	  { string: '4-July-1776', expected: false },
	  { string: '4-Jul-76', expected: false },
	]
  },
  {
	re: /\w(b+c?d+e*f+)/,
	targets: [
	  { string: 'abcdef', expected: true },
	  { string: 'abcdeeef', expected: true },
	  { string: 'bcdef', expected: false },
	  { string: 'abdf', expected: true },
	  { string: 'abcdf', expected: true },
	  { string: 'abbbccdeef', expected: false },
	  { string: 'abcde', expected: false },
	  { string: 'abbbbcdeeeefg', expected: true },
	  { string: 'wxabbbbcdeeeefyz', expected: true }
	]
  },
  {
	re: /(red blue)|(orange blue)|(red\s+green)|(yellow green)|(yellow\s+violet)/,
	targets: [
	  { string: 'red blue', expected: true },
	  { string: 'orange blue', expected: true },
	  { string: 'red     green', expected: true },
	  { string: 'yellow green', expected: true },
	  { string: 'yellow    violet', expected: true },
	  { string: 'red red', expected: false },
	  { string: 'green red', expected: false },
	  { string: 'redviolet', expected: false },
	  { string: 'blue red', expected: false },
	  { string: 'blue', expected: false }
	]
  }
];
