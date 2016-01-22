jQuery( document ).ready(function ($) {
	$(".mobile-menu.noscript").removeClass('noscript');
	$(".mobile-menu, .mobile ul.menu>li>ul>li").click (function(){
			$(".mobile").animate({
				height: 'toggle'
			}, 400);
	});
	$(".mobile>nav>ul.menu>li.expanded>a").click (function(event){
			event.preventDefault();
			$(this).parent().toggleClass("open");
			$(this).parent().children("ul").animate({
				height: 'toggle'
			}, 400);
			return false;
	});
});
