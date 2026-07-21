/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getConcatenation = function(nums) {
    var ans=[...nums,...nums];
    return ans;
};