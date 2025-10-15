class Solution {
    Deque<String> deq = new ArrayDeque<>();
    int n;
    int idx;
    //StringBuilder sb = new StringBuilder();

    public String decodeString(String s) {
        n = s.length();
        for(idx = 0; idx < n; idx++) {
            char c = s.charAt(idx);
            //数字
            if(Character.isDigit(c))
                getDigits(s);
            else if(Character.isLetter(c))
                getString(s);
            else if(c == '[')
                deq.addLast(Character.toString(c));
            else {
                //字符串出栈
                List<String> list  = new ArrayList<>();
                while(!deq.getLast().equals("[")) {
                    list.add(deq.getLast());
                    deq.removeLast();
                }
                //左括号出栈
                deq.removeLast();
                //数字出栈
                int times = Integer.parseInt(deq.getLast());
                deq.removeLast();
                //拼接字符串
                StringBuilder sb = new StringBuilder();
                while(times-- != 0) {
                    for(int i = list.size() - 1; i >= 0; i--) {
                        sb.append(list.get(i));
                    }
                }
                //System.out.println(sb.toString());
                deq.addLast(sb.toString());
            }
        }
        StringBuilder ans = new StringBuilder();
        int size = deq.size();
        for(int i = 0; i < size; i++) {
            ans.append(deq.getFirst());
            deq.removeFirst();
        }
        return ans.toString();
    }

    private void getDigits(String s) {
        StringBuilder sb = new StringBuilder();
        while(idx < n && Character.isDigit(s.charAt(idx))) {
            sb.append(s.charAt(idx));
            idx++;
        }
        idx--;
        deq.addLast(sb.toString());
    }

    private void getString(String s) {
        StringBuilder sb = new StringBuilder();
        while(idx < n && Character.isLetter(s.charAt(idx))) {
            sb.append(s.charAt(idx));
            idx++;
        }
        idx--;
        deq.addLast(sb.toString());
    }
}