package org.knguyenc.sorting;

import junit.framework.TestCase;

import static org.junit.Assert.assertArrayEquals;

public class QuickSortTest extends TestCase {

    public void testVarietyTypesOfArrays() {
        Integer[] integers = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
        String[] strings = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};
        Double[] doubles = {5.2, 4.4, 6.8, 9.5, 0.7, 1.2, 3.2, 5.9};

        QuickSort quickSort = new QuickSort();
        quickSort.sort(integers);
        assertArrayEquals(new Integer[]{2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40}, integers);

        quickSort.sort(strings);
        assertArrayEquals(new String[]{"c", "cpp", "go", "java", "objective-c", "python", "swift"}, strings);

        quickSort.sort(doubles);
        assertArrayEquals(new Double[]{0.7, 1.2, 3.2, 4.4, 5.2, 5.9, 6.8, 9.5}, doubles);
    }
}