jQuery( document ).ready(function ($) {
	$(".mobile-menu").click (function(){
		if ( $(".mobile").css('display') == 'none' ) {
			$(".mobile").css('display','block');
		} else {
			$(".mobile").css('display','none');
		}
	})
});
