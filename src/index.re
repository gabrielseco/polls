[%bs.raw {|require('./index.css')|}];
[%bs.raw {|require('./helpers.re')|}];


external register_service_worker : unit => unit = "" [@@bs.module "./registerServiceWorker"];

ReactDOMRe.renderToElementWithId <App /> "root";
