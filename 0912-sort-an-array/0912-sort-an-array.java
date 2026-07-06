import java.util.Random;

class Solution {

    Random rand = new Random();

    public int[] sortArray(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }

    private void quickSort(int[] nums, int low, int high) {

        if (low >= high) return;

        int random = low + rand.nextInt(high - low + 1);
        swap(nums, random, high);

        int pivot = nums[high];

        int lt = low;
        int i = low;
        int gt = high;

        while (i <= gt) {

            if (nums[i] < pivot) {
                swap(nums, lt++, i++);
            }
            else if (nums[i] > pivot) {
                swap(nums, i, gt--);
            }
            else {
                i++;
            }
        }

        quickSort(nums, low, lt - 1);
        quickSort(nums, gt + 1, high);
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}