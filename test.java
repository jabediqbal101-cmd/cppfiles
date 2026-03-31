public class test {

    public static void main(String[] args) {

         mediaplayer[] media = new mediaplayer[3] ;

         media[0] =new audioplayer();
         media[1] =new vedioplayer();
         media[2] =new audioplayer();


         for (mediaplayer mediaplayer : media ){
            mediaplayer.play();


         }




        
    }
    
}
