package br.edu.ifba.inf011;

import javax.xml.crypto.Data;
import java.util.concurrent.CountDownLatch;

public class Main {
    public static void main(String[] args) throws InterruptedException{
        int numberOfThreads = 100;
        CountDownLatch readyLatch = new CountDownLatch(numberOfThreads);
        CountDownLatch startLatch = new CountDownLatch(1);

        for (int i = 0; i < numberOfThreads; i++){
            new Thread(new Runnable() {
                @Override
                public void run() {
                    readyLatch.countDown();
                    try {
                        startLatch.await();
                        DatabaseConnection instance = DatabaseConnection.getInstance();
                        System.out.println("Instance: " + instance.hashCode());
                    } catch (InterruptedException e){
                        Thread.currentThread().interrupt();
                    }
                }
            }).start();
        }

        readyLatch.await();
        startLatch.countDown();
    }
}
