import org.junit.Assert;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SkipList {

  private static class Node {
    int value;
    Node left, down;

    Node(int x) {
      this(x, null, null);
    }

    Node(int x, Node down, Node left) {
      this.value = x;
      this.down = down;
      this.left = left;
    }
  }

  private List<Node> head;
  private double p;
  private int size;
  private Random rand;

  public SkipList(double p, int maxHeight) {
    this.head = new ArrayList<Node>();
    this.p = p;
    this.size = 0;
    assert maxHeight > 0;
    for (int i = 0; i < maxHeight; i++) {
      head.add(new Node(0));
      if (i > 0) {
        head.get(i).down = head.get(i - 1);
      }
    }
    rand = new Random();
  }

  public SkipList() {
    this(0.5, 32);
  }

  private int randomHeight() {
    int h = 0;
    while (rand.nextDouble() < p && h < 64)
      h++;
    return h + 1;
  }

  public void add(int value) {
    final int maxHeight = head.size();
    Node[] update = new Node[maxHeight];
    Node it = head.get(maxHeight - 1);
    int h = maxHeight - 1;
    while (it != null) {
      if (it.left == null || value < it.left.value) {
        update[h--] = it;
        it = it.down;
      } else {
        it = it.left;
      }
    }
    int currentHeight = randomHeight();
    Node[] current = new Node[currentHeight];
    for (h = 0; h < currentHeight; h++) {
      current[h] = new Node(value);
      if (h > 0) {
        current[h].down = current[h - 1];
      }
    }
    if (maxHeight < currentHeight) {
      for (h = maxHeight; h < currentHeight; h++) {
        head.add(new Node(0, head.get(h - 1), current[h]));
      }
      for (h = 0; h < maxHeight; h++) {
        current[h].left = update[h].left;
        update[h].left = current[h];
      }
    } else {
      for (h = 0; h < currentHeight; h++) {
        current[h].left = update[h].left;
        update[h].left = current[h];
      }
    }
    size++;
  }

  public boolean found(int value) {
    final int maxHeight = head.size();
    Node it = head.get(maxHeight - 1);
    while (it != null) {
      if (it.left == null || value <= it.left.value) {
        if (it.left != null && it.left.value == value) return true;
        it = it.down;
      } else {
        it = it.left;
      }
    }
    return false;
  }

  public boolean remove(int value) {
    final int maxHeight = head.size();
    Node it = head.get(maxHeight - 1);
    boolean isFound = false;
    while (it != null) {
      if (it.left == null || value <= it.left.value) {
        if (it.left != null && it.left.value == value) {
          // do the removing
          isFound = true;
          it.left = it.left.left;
        }
        it = it.down;
      } else {
        it = it.left;
      }
    }
    if (isFound) {
      for (int i = head.size() - 1; i >= 1; i--) {
        if (head.get(i).left == null) {
          head.remove(i);
        }
      }
      --size;
    }
    return isFound;
  }

  public int[] toArrays() {
    int i = 0;
    int[] values = new int[size];
    for (Node it = head.get(0).left; it != null; it = it.left) {
      values[i++] = it.value;
    }
    return values;
  }

  public int size() {
    return size;
  }

  public void print() {
    for (int i = head.size() - 1; i >= 0; i--) {
      Node it = head.get(i).left;
      System.out.print("Height #" + i + ": ");
      while (it != null) {
        System.out.print(it.value + " ");
        it = it.left;
      }
      System.out.println();

    }
  }

  public static void main(String args[]) {
    SkipList skipList = new SkipList();
    int[] values1 = new int[] { 23, 12, 33, 45, 8, 1, 48, 49, 32, 24, 0, 88 };
    int[] result1 = new int[] { 0, 1, 8, 12, 23, 24, 32, 33, 45, 48, 49, 88 };
    for (int i = 0; i < values1.length; i++) {
      skipList.add(values1[i]);
    }
    skipList.print();

    Assert.assertEquals(skipList.size(), result1.length);
    Assert.assertArrayEquals(result1, skipList.toArrays());

    Assert.assertTrue(skipList.remove(0));
    Assert.assertEquals(skipList.size(), result1.length - 1);
    Assert.assertArrayEquals(new int[] { 1, 8, 12, 23, 24, 32, 33, 45, 48, 49, 88 },
      skipList.toArrays());

    Assert.assertFalse(skipList.remove(0));
    Assert.assertEquals(skipList.size(), result1.length - 1);
    Assert.assertArrayEquals(new int[] { 1, 8, 12, 23, 24, 32, 33, 45, 48, 49, 88 },
      skipList.toArrays());

    Assert.assertTrue(skipList.remove(88));
    Assert.assertEquals(skipList.size(), result1.length - 2);
    Assert.assertArrayEquals(new int[] { 1, 8, 12, 23, 24, 32, 33, 45, 48, 49 },
      skipList.toArrays());

    Assert.assertTrue(skipList.remove(33));
    Assert.assertEquals(skipList.size(), result1.length - 3);
    Assert.assertArrayEquals(new int[] { 1, 8, 12, 23, 24, 32, 45, 48, 49 }, skipList.toArrays());

    Assert.assertTrue(skipList.remove(12));
    Assert.assertEquals(skipList.size(), result1.length - 4);
    Assert.assertArrayEquals(new int[] { 1, 8, 23, 24, 32, 45, 48, 49 }, skipList.toArrays());

    for (int value : skipList.toArrays()) {
      Assert.assertTrue(skipList.remove(value));
    }
    Assert.assertTrue(skipList.size() == 0);
  }
}

