import java.util.*;
import java.io.FileInputStream;
import java.io.*;
import java.lang.*;
import java.nio.*;
public class NTFSDump {

    public static void parseMFT(int volumeOffset, File diskImage) throws IOException {
        int bytesPerSector = 512;
        int sectorsPerCluster = 8;
        int numberOfClusters = 4;

        //Total bytes of the disk image
        long lengthOfImage = diskImage.length();
        System.out.println("Total bytes of image: " + lengthOfImage + "\n");

        //the byte offset to get to the mft
        int byteOffset = volumeOffset + (bytesPerSector*sectorsPerCluster*numberOfClusters);
        System.out.println("Byte offset: " + byteOffset + "\n");

        //the size of each mft entry in NTFS
        int mftEntrySize = 1024;

        //creates new byte array of all that stores all MFT entries that are (1024) byte arrays themselves
        byte [][] allMFTEntries = new byte [65][1024];

        InputStream inputStream = new FileInputStream(diskImage);
        inputStream.skip(byteOffset);
        ByteBuffer tempBuf = ByteBuffer.wrap(allMFTEntries[0]);
        tempBuf.order(ByteOrder.LITTLE_ENDIAN);

        // within the MFT entry, grabs the offset to the first attribute
        int offsetToFirstAttribute = tempBuf.getShort(20);

        int nextByte = 0;

        int offset = offsetToFirstAttribute;
        System.out.println("1 : " + offset);

        while(nextByte != 0xFF){
            int offsetToAttributeFromEntryStart = offset;
            System.out.println("2 : " + offsetToAttributeFromEntryStart);
            // read in the first 16 bytes as the attribute header
            byte[] attributeHeader = new byte[16];
            for(int i = 0; i < attributeHeader.length; i++) {
                attributeHeader[i] = allMFTEntries[0][offsetToFirstAttribute + i];
            }
            ByteBuffer attributeHeaderBuf = ByteBuffer.wrap(attributeHeader);
            attributeHeaderBuf.order(ByteOrder.LITTLE_ENDIAN);

            // gets the non resident flag at byte 8
            int residentFlag = (int)attributeHeaderBuf.get(8);

            //if the resident flag is set to 0 then it is resident
            if(0 == 0){
                int offsetToDS = offsetToAttributeFromEntryStart + 16;
                System.out.println("3 : " + offsetToDS);
            }



            // increments the next byte
            nextByte = allMFTEntries[0][offsetToFirstAttribute + 1];
        }
/*
        for (int i = 0; i < this.allMFTEntries.length; i++){
            inputStream.read(this.allMFTEntries[i], 0, 1024);
            ByteBuffer tempBuf = ByteBuffer.wrap(this.allMFTEntries[i]);
            tempBuf.order(ByteOrder.LITTLE_ENDIAN);
            int y = tempBuf.getInt(24);
            int x = tempBuf.getInt(28);
            System.out.println("Used space of file: " + y + "bytes " + "\n");
            System.out.println("Allocated size of file: " + x + "bytes " + "\n");
        }

 */
        inputStream.close();

    }

    public static void main(String[] args) throws IOException {

        // checks to see if the program runs command line file
        if(args.length < 1) {
            System.out.println("Did not run through command line");
            System.exit(1);
        }

        //sets the offset to the mft itself
        int volumeOffset = (Integer.parseInt((args[1])));

        parseMFT(volumeOffset, new File(args[0]));


    }


}
