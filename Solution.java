
// javac -encoding utf-8 Solution.java
class Solution {
    public int[] sortArray(int[] nums) { 

        quickSort(nums,0,nums.length-1);
        return nums;

    }
    public void quickSort (int[] nums, int low, int hight) {

        if (low < hight) {
            int index = partition(nums,low,hight);
            quickSort(nums,low,index-1);
            quickSort(nums,index+1,hight);
        }    

    }
    public int partition (int[] nums, int low, int hight) {

            int pivot = nums[low];
            while (low < hight) {
                //移动hight指针
                while (low < hight && nums[hight] >= pivot) {
                    hight--;
                }
                //填坑
                if (low < hight) nums[low] = nums[hight];
                while (low < hight && nums[low] <= pivot) {
                    low++;
                }
                //填坑
                if (low < hight) nums[hight] = nums[low];
            }
            //基准数放到合适的位置
            nums[low] = pivot;
            return low;
    }
    
    public static void main(String[] args){
        int[] a = {1,22,2,3,222,-1,-222};
        Solution s = new Solution();
        s.sortArray(a);
        for(int i : a){System.out.println(i);}
        
    }   
}
/*
class Solution {
    public int[] sortArray (int[] nums) {   

        quickSort(nums,0,nums.length-1);
        return nums;

    }

    public void quickSort (int[] nums, int low, int hight) {

        if (low < hight) {
            int index = partition(nums,low,hight);
            quickSort(nums,low,index-1);
            quickSort(nums,index+1,hight);
        } 

    }

    public int partition (int[] nums, int low, int hight) {

            int pivot = nums[low];
            int start = low;

            while (low < hight) {
                while (low < hight && nums[hight] >= pivot) hight--;           
                while (low < hight && nums[low] <= pivot) low++;
                if (low >= hight) break;
                swap(nums, low, hight);  
            }
            //基准值归位
            swap(nums,start,low);
            return low;
    }  
    public void swap (int[] nums, int i, int j) {      
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
     } 
}


class Solution {

     public int[] sortArray(int[] nums) {
        Stack<Integer> stack = new Stack<>();
        stack.push(nums.length - 1);
        stack.push(0);
        while (!stack.isEmpty()) {
            int low = stack.pop();
            int hight = stack.pop();

            if (low < hight) {
                int index = partition(nums, low, hight);
                stack.push(index - 1);
                stack.push(low);
                stack.push(hight);
                stack.push(index + 1);
            }
        }
        return nums;
    }

    public int partition (int[] nums, int low, int hight) {

            int pivot = nums[low];
            int start = low;
            while (low < hight) {

                while (low < hight && nums[hight] >= pivot) hight--;           
                while (low < hight && nums[low] <= pivot) low++;
                if (low >= hight) break;
                swap(nums, low, hight); 
            }
            swap(nums,start,low);
            return low;

    } 
    public void swap (int[] nums, int i, int j) {    
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }  
}class Solution {
    public int[] sortArray(int[] nums) {       
        quickSort(nums,0,nums.length-1);
        return nums;
    }
    public void quickSort (int[] nums, int low, int hight) {
        if (low < hight) {
            int index = partition(nums,low,hight);
            quickSort(nums,low,index-1);
            quickSort(nums,index+1,hight);
        }       
    }

    public int partition (int[] nums, int low, int hight) {
            //三数取中，大家也可以使用其他方法
            int mid = low + ((hight-low) >> 1);
            if (nums[low] > nums[hight]) swap(nums,low,hight);
            if (nums[mid] > nums[hight]) swap(nums,mid,hight);
            if (nums[mid] > nums[low]) swap(nums,mid,low); 
            //下面和之前一样，仅仅是多了上面几行代码
            int pivot = nums[low];
            int start = low;
            while (low < hight) {
                while (low < hight && nums[hight] >= pivot) hight--;           
                while (low < hight && nums[low] <= pivot) low++;
                if (low >= hight) break;
                swap(nums, low, hight); 
            }
            swap(nums,start,low);
            return low;
    }  
    public void swap (int[] nums, int i, int j) {     
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }  
}


三数取中+插入排序

class Solution {
    private static final int INSERTION_SORT_MAX_LENGTH = 7;

    public int[] sortArray(int[] nums) {      
        quickSort(nums,0,nums.length-1);
        return nums;
    }

    public void quickSort (int[] nums, int low, int hight) {

            if (hight - low <= INSERTION_SORT_MAX_LENGTH) {
                insertSort(nums,low,hight);
                return;
            }               
            int index = partition(nums,low,hight);
            quickSort(nums,low,index-1);
            quickSort(nums,index+1,hight);         
    }

    public int partition (int[] nums, int low, int hight) {
            //三数取中，大家也可以使用其他方法
            int mid = low + ((hight-low) >> 1);
            if (nums[low] > nums[hight]) swap(nums,low,hight);
            if (nums[mid] > nums[hight]) swap(nums,mid,hight);
            if (nums[mid] > nums[low]) swap(nums,mid,low);   
            int pivot = nums[low];
            int start = low;
            while (low < hight) {
                while (low < hight && nums[hight] >= pivot) hight--;           
                while (low < hight && nums[low] <= pivot) low++;
                if (low >= hight) break;
                swap(nums, low, hight); 
            }
            swap(nums,start,low);
            return low;
    } 

    public void insertSort (int[] nums, int low, int hight) {

        for (int i = low+1; i <= hight; ++i) {
            int temp = nums[i];
            int j;
            for (j = i-1; j >= 0; --j) {
                if (temp < nums[j]) {
                    nums[j+1] = nums[j];
                    continue;
                } 
                break;
            }
            nums[j+1] = temp;
        }
    } 
    public void swap (int[] nums, int i, int j) {

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    } 
}


三数取中+三向切分+插入排序

class Solution {
    private static final int INSERTION_SORT_MAX_LENGTH = 7;
    public int[] sortArray(int[] nums) {
        quickSort(nums,0,nums.length-1);
        return nums;

    }
    public void quickSort(int nums[], int low, int hight) {
        //插入排序
        if (hight - low <= INSERTION_SORT_MAX_LENGTH) {
            insertSort(nums,low,hight);
            return;
        }
        //三数取中
        int mid = low + ((hight-low) >> 1);
        if (nums[low] > nums[hight]) swap(nums,low,hight);
        if (nums[mid] > nums[hight]) swap(nums,mid,hight);
        if (nums[mid] > nums[low]) swap(nums,mid,low);
        //三向切分
        int left = low,  i = low + 1, right = hight;
        int pvoit = nums[low];
        while (i <= right) {
            if (pvoit < nums[i]) {
                swap(nums,i,right);
                right--;
            } else if (pvoit == nums[i]) {
                i++;
            } else {
                swap(nums,left,i);
                left++;
                i++;
            }
        }
        quickSort(nums,low,left-1);
        quickSort(nums,right+1,hight);
    }
     public void insertSort (int[] nums, int low, int hight) {

        for (int i = low+1; i <= hight; ++i) {
            int temp = nums[i];
            int j;
            for (j = i-1; j >= 0; --j) {
                if (temp < nums[j]) {
                    nums[j+1] = nums[j];
                    continue;
                } 
                break;
            }
            nums[j+1] = temp;
        }
    } 
    public  void swap (int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
*/
    
